#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	check_line(char *line, const char *expected, const char *label)
{
	if (!line)
	{
		fprintf(stderr, "[FAIL] %s: line is NULL\n", label);
		return (1);
	}
	if (strcmp(line, expected) != 0)
	{
		fprintf(stderr, "[FAIL] %s: expected '%s', got '%s'\n", label,
			expected, line);
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	main(void)
{
	char	path[] = "/tmp/gnl_mandatory_XXXXXX";
	int		fd;
	char	*line;

	fd = mkstemp(path);
	if (fd < 0)
		return (perror("mkstemp"), 1);
	if (write(fd, "alpha\n\nbeta", 11) != 11)
		return (perror("write"), close(fd), unlink(path), 1);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (perror("lseek"), close(fd), unlink(path), 1);
	line = get_next_line(fd);
	if (check_line(line, "alpha\n", "line1") != 0)
		return (close(fd), unlink(path), 1);
	line = get_next_line(fd);
	if (check_line(line, "\n", "line2_empty") != 0)
		return (close(fd), unlink(path), 1);
	line = get_next_line(fd);
	if (check_line(line, "beta", "line3_last") != 0)
		return (close(fd), unlink(path), 1);
	line = get_next_line(fd);
	if (line != NULL)
		return (fprintf(stderr, "[FAIL] EOF should return NULL\n"), free(line),
			close(fd), unlink(path), 1);
	line = get_next_line(-1);
	if (line != NULL)
		return (fprintf(stderr, "[FAIL] invalid fd should return NULL\n"),
			free(line), close(fd), unlink(path), 1);
	close(fd);
	unlink(path);
	printf("[OK] get_next_line mandatory strict\n");
	return (0);
}

#include "get_next_line_bonus.h"
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

static int	fill_file(int fd, const char *content)
{
	size_t	len;

	len = strlen(content);
	if (write(fd, content, len) != (ssize_t)len)
		return (1);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (1);
	return (0);
}

int	main(void)
{
	char	path_a[] = "/tmp/gnl_bonus_a_XXXXXX";
	char	path_b[] = "/tmp/gnl_bonus_b_XXXXXX";
	int		fd_a;
	int		fd_b;
	char	*line;

	fd_a = mkstemp(path_a);
	fd_b = mkstemp(path_b);
	if (fd_a < 0 || fd_b < 0)
		return (perror("mkstemp"), 1);
	if (fill_file(fd_a, "A1\nA2\n") != 0 || fill_file(fd_b, "B1\nB2\n") != 0)
		return (perror("write/lseek"), close(fd_a), close(fd_b), unlink(path_a),
			unlink(path_b), 1);
	line = get_next_line(fd_a);
	if (check_line(line, "A1\n", "fd_a_line1") != 0)
		return (close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	line = get_next_line(fd_b);
	if (check_line(line, "B1\n", "fd_b_line1") != 0)
		return (close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	line = get_next_line(fd_a);
	if (check_line(line, "A2\n", "fd_a_line2") != 0)
		return (close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	line = get_next_line(fd_b);
	if (check_line(line, "B2\n", "fd_b_line2") != 0)
		return (close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	line = get_next_line(fd_a);
	if (line != NULL)
		return (fprintf(stderr, "[FAIL] fd_a EOF should return NULL\n"), free(line),
			close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	line = get_next_line(fd_b);
	if (line != NULL)
		return (fprintf(stderr, "[FAIL] fd_b EOF should return NULL\n"), free(line),
			close(fd_a), close(fd_b), unlink(path_a), unlink(path_b), 1);
	close(fd_a);
	close(fd_b);
	unlink(path_a);
	unlink(path_b);
	printf("[OK] get_next_line bonus multi-fd strict\n");
	return (0);
}

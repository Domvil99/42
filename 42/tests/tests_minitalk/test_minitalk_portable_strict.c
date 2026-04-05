#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int	read_line_timeout(int fd, char *buf, size_t cap, int seconds)
{
	fd_set	set;
	int		ret;
	size_t	idx;
	char	c;

	idx = 0;
	while (idx + 1 < cap)
	{
		FD_ZERO(&set);
		FD_SET(fd, &set);
		ret = select(fd + 1, &set, NULL, NULL, &(struct timeval){seconds, 0});
		if (ret <= 0)
			return (0);
		if (read(fd, &c, 1) != 1)
			return (0);
		buf[idx++] = c;
		if (c == '\n')
			break ;
	}
	buf[idx] = '\0';
	return (idx > 0);
}

static int	parse_server_pid(const char *line, pid_t *pid)
{
	long	value;

	value = 0;
	while (*line && !isdigit((unsigned char)*line))
		line++;
	if (!*line)
		return (0);
	while (*line && isdigit((unsigned char)*line))
	{
		value = (value * 10) + (*line - '0');
		line++;
	}
	if (value <= 0 || value > 2147483647)
		return (0);
	*pid = (pid_t)value;
	return (1);
}

static int	run_client(const char *client_path, pid_t server_pid, const char *msg)
{
	pid_t	pid;
	int		status;
	char	pid_str[32];

	snprintf(pid_str, sizeof(pid_str), "%d", server_pid);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		execl(client_path, client_path, pid_str, msg, NULL);
		exit(1);
	}
	if (waitpid(pid, &status, 0) < 0)
		return (0);
	usleep(80000);
	return (WIFEXITED(status) && WEXITSTATUS(status) == 0);
}

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	server_proc;
	pid_t	server_pid;
	char	line[256];
	char	output[4096];
	ssize_t	bytes;
	ssize_t	total;

	if (argc != 3)
		return (fprintf(stderr, "Uso: %s <server_bin> <client_bin>\n", argv[0]), 1);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	server_proc = fork();
	if (server_proc < 0)
		return (perror("fork"), 1);
	if (server_proc == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execl(argv[1], argv[1], NULL);
		exit(1);
	}
	close(pipefd[1]);
	if (!read_line_timeout(pipefd[0], line, sizeof(line), 3))
		return (fprintf(stderr, "[FAIL] server did not print PID\n"), 1);
	if (!parse_server_pid(line, &server_pid))
		return (fprintf(stderr, "[FAIL] could not parse server PID\n"), 1);
	if (!run_client(argv[2], server_pid, "abc")
		|| !run_client(argv[2], server_pid, "XYZ")
		|| !run_client(argv[2], server_pid, ""))
		return (fprintf(stderr, "[FAIL] client execution failed\n"), 1);
	usleep(250000);
	kill(server_proc, SIGTERM);
	waitpid(server_proc, NULL, 0);
	total = 0;
	while (total < (ssize_t)sizeof(output) - 1)
	{
		bytes = read(pipefd[0], output + total, sizeof(output) - 1 - total);
		if (bytes < 0)
			return (perror("read"), 1);
		if (bytes == 0)
			break ;
		total += bytes;
	}
	output[total] = '\0';
	close(pipefd[0]);
	if (!strstr(output, "abc") || !strstr(output, "XYZ"))
		return (fprintf(stderr, "[FAIL] message output not found\n"), 1);
	printf("[OK] minitalk portable strict\n");
	return (0);
}

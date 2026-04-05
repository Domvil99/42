#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		status;

	if (argc != 2)
		return (fprintf(stderr, "Uso: %s <client_bin>\n", argv[0]), 1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		execl(argv[1], argv[1], "badpid", "hola", NULL);
		exit(1);
	}
	if (waitpid(pid, &status, 0) < 0)
		return (1);
	if (!WIFEXITED(status) || WEXITSTATUS(status) == 0)
		return (fprintf(stderr, "[FAIL] invalid PID should fail\n"), 1);
	printf("[OK] minitalk invalid PID test\n");
	return (0);
}

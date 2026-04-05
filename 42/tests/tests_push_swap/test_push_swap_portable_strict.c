#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	run_cmd(const char *cmd)
{
	int	status;

	status = system(cmd);
	if (status != 0)
		fprintf(stderr, "[FAIL] command failed: %s\n", cmd);
	return (status);
}

static int	check_error_case(const char *push_swap, const char *args)
{
	char	cmd[2048];

	snprintf(cmd, sizeof(cmd), "%s %s > /tmp/ps_out.txt 2> /tmp/ps_err.txt",
		push_swap, args);
	(void)system(cmd);
	snprintf(cmd, sizeof(cmd), "grep -q Error /tmp/ps_err.txt");
	if (run_cmd(cmd) != 0)
		return (fprintf(stderr, "[FAIL] expected Error for: %s\n", args), 1);
	return (0);
}

static int	check_ok_case(const char *push_swap, const char *checker,
		const char *args)
{
	char	cmd[4096];

	snprintf(cmd, sizeof(cmd),
		"%s %s | %s %s > /tmp/ps_check.txt 2>/tmp/ps_check_err.txt",
		push_swap, args, checker, args);
	if (run_cmd(cmd) != 0)
		return (1);
	snprintf(cmd, sizeof(cmd), "grep -qx OK /tmp/ps_check.txt");
	if (run_cmd(cmd) != 0)
		return (fprintf(stderr, "[FAIL] checker not OK for: %s\n", args), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	const char	*push_swap;
	const char	*checker;

	if (argc != 3)
	{
		fprintf(stderr, "Uso: %s /ruta/push_swap /ruta/checker\n", argv[0]);
		return (1);
	}
	push_swap = argv[1];
	checker = argv[2];
	if (check_error_case(push_swap, "1 2 2") != 0)
		return (1);
	if (check_error_case(push_swap, "1 a 3") != 0)
		return (1);
	if (check_ok_case(push_swap, checker, "2 1") != 0)
		return (1);
	if (check_ok_case(push_swap, checker, "3 2 1") != 0)
		return (1);
	if (check_ok_case(push_swap, checker, "5 1 4 2 3") != 0)
		return (1);
	printf("[OK] push_swap portable strict\n");
	return (0);
}

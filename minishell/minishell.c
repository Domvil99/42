/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char		*input;
	t_command	*cmd;

	(void)argc;
	(void)argv;
	shell.env = create_env(envp);
	shell.pwd = getcwd(NULL, 0);
	shell.oldpwd = NULL;
	shell.exit_status = 0;
	setup_signals();
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		if (g_signal_received == SIGINT)
		{
			shell.exit_status = 130;
			g_signal_received = 0;
		}
		cmd = parse_input(input, &shell);
		if (cmd)
			execute_commands(&shell, cmd);
		free(input);
		free_commands(cmd);
	}
	free(shell.pwd);
	free(shell.oldpwd);
	free_env(shell.env);
	return (shell.exit_status);
}
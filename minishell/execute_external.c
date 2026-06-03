/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_external(t_shell *shell, t_command *cmd)
{
	pid_t	pid;
	char	*path;
	char	**env;

	path = resolve_executable_path(shell, cmd->args[0]);
	if (!path)
	{
		ft_printf("minishell: %s: command not found\n", cmd->args[0]);
		shell->exit_status = 127;
		return ;
	}
	env = env_to_array(shell->env);
	pid = fork();
	if (pid == 0)
	{
		if (cmd->input_file && setup_input_redirect(cmd->input_file) < 0)
			exit(1);
		if (cmd->output_file && setup_output_redirect(cmd->output_file,
			cmd->append) < 0)
			exit(1);
		execve(path, cmd->args, env);
		perror("execve");
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &shell->exit_status, 0);
		shell->exit_status = WEXITSTATUS(shell->exit_status);
	}
	else
	{
		perror("fork");
		shell->exit_status = 1;
	}
	free(path);
	free_string_array(env);
}

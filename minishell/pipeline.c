/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_commands(t_command *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

static void	close_pipes(int (*pipes)[2], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

static void	execute_pipeline_child(t_shell *shell, t_command *cmd,
	int index, int command_count, int (*pipes)[2])
{
	char	*path;
	char	**env;

	if (index > 0)
	{
		if (dup2(pipes[index - 1][0], STDIN_FILENO) < 0)
		{
			perror("dup2");
			exit(1);
		}
	}
	if (index < command_count - 1)
	{
		if (dup2(pipes[index][1], STDOUT_FILENO) < 0)
		{
			perror("dup2");
			exit(1);
		}
	}
	close_pipes(pipes, command_count - 1);
	if (cmd->input_file && setup_input_redirect(cmd->input_file) < 0)
		exit(1);
	if (cmd->output_file && setup_output_redirect(cmd->output_file,
		cmd->append) < 0)
		exit(1);
	if (is_builtin(cmd->args[0]))
		exit(execute_builtin_as_child(shell, cmd));
	path = resolve_executable_path(shell, cmd->args[0]);
	if (!path)
	{
		ft_printf("minishell: %s: command not found\n", cmd->args[0]);
		exit(127);
	}
	env = env_to_array(shell->env);
	execve(path, cmd->args, env);
	perror("execve");
	free(path);
	if (env)
	{
		int	j;

		j = 0;
		while (env[j])
		{
			free(env[j]);
			j++;
		}
		free(env);
	}
	exit(1);
}

void	execute_pipeline(t_shell *shell, t_command *cmd)
{
	int		command_count;
	int		(*pipes)[2];
	pid_t	*pids;
	int		i;
	int		status;
	t_command	*current;

	command_count = count_commands(cmd);
	if (command_count < 2)
		return ;
	pipes = malloc(sizeof(int) * 2 * (command_count - 1));
	if (!pipes)
	{
		shell->exit_status = 1;
		return ;
	}
	i = 0;
	while (i < command_count - 1)
	{
		if (pipe(pipes[i]) < 0)
		{
			close_pipes(pipes, i);
			free(pipes);
			shell->exit_status = 1;
			return ;
		}
		i++;
	}
	pids = malloc(sizeof(pid_t) * command_count);
	if (!pids)
	{
		close_pipes(pipes, command_count - 1);
		free(pipes);
		shell->exit_status = 1;
		return ;
	}
	current = cmd;
	i = 0;
	while (current)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			execute_pipeline_child(shell, current, i, command_count, pipes);
		else if (pids[i] < 0)
		{
			perror("fork");
			shell->exit_status = 1;
			break ;
		}
		current = current->next;
		i++;
	}
	close_pipes(pipes, command_count - 1);
	free(pipes);
	while (i > 0)
	{
		i--;
		if (waitpid(pids[i], &status, 0) > 0 && i == command_count - 1)
		{
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
			else
				shell->exit_status = 1;
		}
	}
	free(pids);
}

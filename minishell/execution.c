/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 ||
		ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0 ||
		ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0 ||
		ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

void	execute_builtin(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		shell->exit_status = ft_cd(shell, cmd->args);
	else if (ft_strcmp(cmd->args[0], "echo") == 0)
		shell->exit_status = ft_echo(cmd->args);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		shell->exit_status = ft_pwd(shell);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		shell->exit_status = ft_export(shell, cmd->args);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		shell->exit_status = ft_unset(shell, cmd->args);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		shell->exit_status = ft_env(shell);
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		ft_exit(shell, cmd->args);
}

static void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*join_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (path);
}

char	*resolve_executable_path(t_shell *shell, char *cmd)
{
	char	*path_value;
	char	**paths;
	char	*candidate;
	int		i;

	if (ft_strchr(cmd, '/') != NULL)
		return (ft_strdup(cmd));
	path_value = get_env_value(shell->env, "PATH");
	if (!path_value)
		return (NULL);
	paths = ft_split(path_value, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		candidate = join_path(paths[i], cmd);
		if (candidate && access(candidate, X_OK) == 0)
		{
			free_string_array(paths);
			return (candidate);
		}
		free(candidate);
		i++;
	}
	free_string_array(paths);
	return (NULL);
}

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

void	execute_commands(t_shell *shell, t_command *cmd)
{
	if (is_builtin(cmd->args[0]))
		execute_builtin(shell, cmd);
	else
		execute_external(shell, cmd);
}
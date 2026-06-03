/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:40:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 ||
		ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0 ||
		ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0 ||
		ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin_as_child(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (ft_cd(shell, cmd->args));
	else if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (ft_echo(cmd->args));
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (ft_pwd(shell));
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		return (ft_export(shell, cmd->args));
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (ft_unset(shell, cmd->args));
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		return (ft_env(shell));
	return (1);
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

static int	setup_input_redirect(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", filename);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	setup_output_redirect(char *filename, int append)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
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
		if (cmd->input_file && setup_input_redirect(cmd->input_file) < 0)
			exit(1);
		if (cmd->output_file && setup_output_redirect(cmd->output_file, cmd->append) < 0)
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

void	execute_with_redirections(t_shell *shell, t_command *cmd)
{
	pid_t	pid;
	char	*path;
	char	**env;

	if (is_builtin(cmd->args[0]))
	{
		if (cmd->input_file)
			setup_input_redirect(cmd->input_file);
		if (cmd->output_file)
			setup_output_redirect(cmd->output_file, cmd->append);
		execute_builtin(shell, cmd);
		return ;
	}
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
		if (cmd->output_file && setup_output_redirect(cmd->output_file, cmd->append) < 0)
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

void	execute_commands(t_shell *shell, t_command *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (is_builtin(cmd->args[0]))
	{
		if (cmd->next == NULL)
			execute_builtin(shell, cmd);
		else
			execute_external(shell, cmd);
	}
	else
	{
		if ((cmd->input_file || cmd->output_file) && !cmd->next)
			execute_with_redirections(shell, cmd);
		else
			execute_external(shell, cmd);
	}
}

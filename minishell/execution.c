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

void	free_string_array(char **array)
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

static char	*get_heredoc_path(void)
{
	static int	counter;
	char		*pid_str;
	char		*count_str;
	char		*tmp;
	char		*path;

	pid_str = ft_itoa(getpid());
	count_str = ft_itoa(++counter);
	if (!pid_str || !count_str)
	{
		free(pid_str);
		free(count_str);
		return (NULL);
	}
	tmp = ft_strjoin("/tmp/minishell_heredoc_", pid_str);
	if (!tmp)
	{
		free(pid_str);
		free(count_str);
		return (NULL);
	}
	path = ft_strjoin(tmp, "_");
	free(tmp);
	if (!path)
	{
		free(pid_str);
		free(count_str);
		return (NULL);
	}
	tmp = ft_strjoin(path, count_str);
	free(path);
	if (!tmp)
	{
		free(pid_str);
		free(count_str);
		return (NULL);
	}
	path = ft_strjoin(tmp, ".tmp");
	free(tmp);
	free(pid_str);
	free(count_str);
	return (path);
}

static int	write_heredoc_to_file(const char *limiter, const char *path)
{
	int		fd;
	char	*line;
	size_t	len;

	extern int g_signal_received;

	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (g_signal_received == SIGINT)
		{
			/* Interrupted by Ctrl-C: cleanup and signal caller */
			if (line)
				free(line);
			close(fd);
			return (-1);
		}
		if (!line)
			break ;
		if (strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		len = ft_strlen(line);
		if (write(fd, line, len) != (ssize_t)len || write(fd, "\n", 1) != 1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

static int	prepare_heredoc_for_command(t_command *cmd)
{
	char	*path;

	if (!cmd || !cmd->heredoc || !cmd->heredoc_delimiter)
		return (0);
	path = get_heredoc_path();
	if (!path)
		return (-1);
	if (write_heredoc_to_file(cmd->heredoc_delimiter, path) < 0)
	{
		unlink(path);
		free(path);
		return (-1);
	}
	free(cmd->input_file);
	cmd->input_file = path;
	free(cmd->heredoc_delimiter);
	cmd->heredoc_delimiter = NULL;
	return (0);
}

int	prepare_heredocs(t_command *cmd)
{
	while (cmd)
	{
		if (prepare_heredoc_for_command(cmd) < 0)
			return (-1);
		cmd = cmd->next;
	}
	return (0);
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
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "echo") == 0 ||
		strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin_as_child(t_shell *shell, t_command *cmd)
{
	if (strcmp(cmd->args[0], "cd") == 0)
		return (ft_cd(shell, cmd->args));
	else if (strcmp(cmd->args[0], "echo") == 0)
		return (ft_echo(cmd->args));
	else if (strcmp(cmd->args[0], "pwd") == 0)
		return (ft_pwd(shell));
	else if (strcmp(cmd->args[0], "export") == 0)
		return (ft_export(shell, cmd->args));
	else if (strcmp(cmd->args[0], "unset") == 0)
		return (ft_unset(shell, cmd->args));
	else if (strcmp(cmd->args[0], "env") == 0)
		return (ft_env(shell));
	return (1);
}

void	execute_builtin(t_shell *shell, t_command *cmd)
{
	if (strcmp(cmd->args[0], "cd") == 0)
		shell->exit_status = ft_cd(shell, cmd->args);
	else if (strcmp(cmd->args[0], "echo") == 0)
		shell->exit_status = ft_echo(cmd->args);
	else if (strcmp(cmd->args[0], "pwd") == 0)
		shell->exit_status = ft_pwd(shell);
	else if (strcmp(cmd->args[0], "export") == 0)
		shell->exit_status = ft_export(shell, cmd->args);
	else if (strcmp(cmd->args[0], "unset") == 0)
		shell->exit_status = ft_unset(shell, cmd->args);
	else if (strcmp(cmd->args[0], "env") == 0)
		shell->exit_status = ft_env(shell);
	else if (strcmp(cmd->args[0], "exit") == 0)
		ft_exit(shell, cmd->args);
}

int	setup_input_redirect(char *filename)
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

int	setup_output_redirect(char *filename, int append)
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

static int	backup_streams(int *stdin_backup, int *stdout_backup)
{
	*stdin_backup = -1;
	*stdout_backup = -1;
	*stdin_backup = dup(STDIN_FILENO);
	if (*stdin_backup < 0)
		return (-1);
	*stdout_backup = dup(STDOUT_FILENO);
	if (*stdout_backup < 0)
	{
		close(*stdin_backup);
		return (-1);
	}
	return (0);
}

static void	restore_streams(int stdin_backup, int stdout_backup)
{
	if (stdin_backup >= 0)
	{
		dup2(stdin_backup, STDIN_FILENO);
		close(stdin_backup);
	}
	if (stdout_backup >= 0)
	{
		dup2(stdout_backup, STDOUT_FILENO);
		close(stdout_backup);
	}
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
	int	stdin_backup;
	int	stdout_backup;

	if (is_builtin(cmd->args[0]))
	{
		if (backup_streams(&stdin_backup, &stdout_backup) < 0)
		{
			shell->exit_status = 1;
			return ;
		}
		if (cmd->input_file)
		{
			if (setup_input_redirect(cmd->input_file) < 0)
			{
				restore_streams(stdin_backup, stdout_backup);
				shell->exit_status = 1;
				return ;
			}
		}
		if (cmd->output_file)
		{
			if (setup_output_redirect(cmd->output_file, cmd->append) < 0)
			{
				restore_streams(stdin_backup, stdout_backup);
				shell->exit_status = 1;
				return ;
			}
		}
		execute_builtin(shell, cmd);
		restore_streams(stdin_backup, stdout_backup);
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
	int i;

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
	else
	{
		char	*path;
		char	**env;

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
		free_string_array(env);
		exit(1);
	}
}

static void	execute_pipeline(t_shell *shell, t_command *cmd)
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
			perror("pipe");
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
	command_count = i;
	i = 0;
	while (i < command_count)
	{
		if (waitpid(pids[i], &status, 0) > 0 && i == command_count - 1)
		{
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
			else
				shell->exit_status = 1;
		}
		i++;
	}
	free(pids);
}

static void	execute_logical_chain(t_shell *shell, t_command *cmd)
{
	t_command	*current;

	current = cmd;
	while (current)
	{
		if (is_builtin(current->args[0]))
		{
			if ((current->input_file || current->output_file))
				execute_with_redirections(shell, current);
			else
				execute_builtin(shell, current);
		}
		else
		{
			if ((current->input_file || current->output_file))
				execute_with_redirections(shell, current);
			else
				execute_external(shell, current);
		}
		if (current->operator_type == 2)
		{
			if (shell->exit_status != 0)
				break ;
		}
		else if (current->operator_type == 3)
		{
			if (shell->exit_status == 0)
				break ;
		}
		current = current->next;
	}
}

static int	has_pipe_operator(t_command *cmd)
{
	while (cmd)
	{
		if (cmd->operator_type == 1)
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

static int	has_logical_operator(t_command *cmd)
{
	while (cmd)
	{
		if (cmd->operator_type == 2 || cmd->operator_type == 3)
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

void	execute_commands(t_shell *shell, t_command *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (prepare_heredocs(cmd) < 0)
	{
		/* If heredoc was aborted by SIGINT, reflect Bash-like 130 exit */
		if (g_signal_received == SIGINT)
			shell->exit_status = 130;
		else
			shell->exit_status = 1;
		return ;
	}
	if (has_pipe_operator(cmd))
	{
		execute_pipeline(shell, cmd);
		return ;
	}
	if (has_logical_operator(cmd))
	{
		execute_logical_chain(shell, cmd);
		return ;
	}
	if (is_builtin(cmd->args[0]))
	{
		if ((cmd->input_file || cmd->output_file))
			execute_with_redirections(shell, cmd);
		else
			execute_builtin(shell, cmd);
	}
	else
	{
		if ((cmd->input_file || cmd->output_file))
			execute_with_redirections(shell, cmd);
		else
			execute_external(shell, cmd);
	}
}

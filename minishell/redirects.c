/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	backup_streams(int *stdin_backup, int *stdout_backup)
{
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

void	restore_streams(int stdin_backup, int stdout_backup)
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

void	execute_with_redirections(t_shell *shell, t_command *cmd)
{
	int	stdin_backup;
	int	stdout_backup;

	if (is_builtin(cmd->args[0]))
	{
		if (backup_streams(&stdin_backup, &stdout_backup) < 0)
		{
			shell->exit_status = 1;
			return ;
		}
		if (cmd->input_file && setup_input_redirect(cmd->input_file) < 0)
		{
			restore_streams(stdin_backup, stdout_backup);
			shell->exit_status = 1;
			return ;
		}
		if (cmd->output_file && setup_output_redirect(cmd->output_file,
			cmd->append) < 0)
		{
			restore_streams(stdin_backup, stdout_backup);
			shell->exit_status = 1;
			return ;
		}
		execute_builtin(shell, cmd);
		restore_streams(stdin_backup, stdout_backup);
		return ;
	}
	execute_external(shell, cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(pid_str);
	if (!tmp)
	{
		free(count_str);
		return (NULL);
	}
	path = ft_strjoin(tmp, "_");
	free(tmp);
	if (!path)
	{
		free(count_str);
		return (NULL);
	}
	tmp = ft_strjoin(path, count_str);
	free(path);
	free(count_str);
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, ".tmp");
	free(tmp);
	return (path);
}

static int	write_heredoc_to_file(const char *limiter, const char *path)
{
	int		fd;
	char	*line;
	size_t	len;

	extern int	g_signal_received;

	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (g_signal_received == SIGINT)
		{
			if (line)
				free(line);
			close(fd);
			return (-1);
		}
		if (!line)
			break ;
		if (ft_strcmp(line, limiter) == 0)
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

int	prepare_heredoc_for_command(t_command *cmd)
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

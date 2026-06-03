/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin_as_child(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (ft_cd(shell, cmd->args));
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (ft_echo(cmd->args));
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (ft_pwd(shell));
	if (ft_strcmp(cmd->args[0], "export") == 0)
		return (ft_export(shell, cmd->args));
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (ft_unset(shell, cmd->args));
	if (ft_strcmp(cmd->args[0], "env") == 0)
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

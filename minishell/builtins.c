/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_shell *shell, char **args)
{
	char	*path;

	if (!args[1])
		path = get_env_value(shell->env, "HOME");
	else
		path = args[1];
	if (!path)
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (1);
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	free(shell->oldpwd);
	shell->oldpwd = shell->pwd;
	shell->pwd = getcwd(NULL, 0);
	set_env_value(&shell->env, "PWD", shell->pwd);
	set_env_value(&shell->env, "OLDPWD", shell->oldpwd);
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}

int	ft_pwd(t_shell *shell)
{
	ft_putendl_fd(shell->pwd, 1);
	return (0);
}


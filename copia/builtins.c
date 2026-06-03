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

int	ft_export(t_shell *shell, char **args)
{
	char	*equal_pos;
	char	*key;
	char	*value;
	int		i;

	i = 1;
	if (!args[1])
	{
		t_env *tmp = shell->env;
		while (tmp)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(tmp->value, 1);
			tmp = tmp->next;
		}
		return (0);
	}
	while (args[i])
	{
		equal_pos = ft_strchr(args[i], '=');
		if (equal_pos)
		{
			key = ft_substr(args[i], 0, equal_pos - args[i]);
			value = ft_strdup(equal_pos + 1);
			if (key && value)
				set_env_value(&shell->env, key, value);
			free(key);
			free(value);
		}
		else
			ft_printf("export: '%s': not a valid identifier\n", args[i]);
		i++;
	}
	return (0);
}

int	ft_unset(t_shell *shell, char **args)
{
	t_env	*tmp;
	t_env	*prev;
	int		i;

	i = 1;
	while (args[i])
	{
		tmp = shell->env;
		prev = NULL;
		while (tmp)
		{
			if (ft_strcmp(tmp->key, args[i]) == 0)
			{
				if (prev)
					prev->next = tmp->next;
				else
					shell->env = tmp->next;
				free(tmp->key);
				free(tmp->value);
				free(tmp);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

int	ft_env(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		ft_putstr_fd(tmp->key, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(tmp->value, 1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_exit(t_shell *shell, char **args)
{
	int	status;

	status = shell->exit_status;
	if (args[1])
		status = ft_atoi(args[1]);
	exit(status);
}
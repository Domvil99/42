/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	process_export_arg(t_shell *shell, char *arg)
{
	char	*equal_pos;
	char	*key;
	char	*value;

	equal_pos = ft_strchr(arg, '=');
	if (equal_pos)
	{
		key = ft_substr(arg, 0, equal_pos - arg);
		value = ft_strdup(equal_pos + 1);
	}
	else
	{
		key = ft_strdup(arg);
		value = ft_strdup("");
	}
	if (key && value && is_valid_identifier(key))
		set_env_value(&shell->env, key, value);
	else
		ft_printf("export: '%s': not a valid identifier\n", arg);
	free(key);
	free(value);
}

int	ft_export(t_shell *shell, char **args)
{
	int	i;

	i = 1;
	if (!args[1])
		return (ft_env(shell));
	while (args[i])
	{
		process_export_arg(shell, args[i]);
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

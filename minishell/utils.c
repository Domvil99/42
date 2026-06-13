/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_env_node(char *env_str)
{
	t_env	*node;
	char	*equal;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	equal = ft_strchr(env_str, '=');
	if (equal)
	{
		node->key = ft_substr(env_str, 0, equal - env_str);
		node->value = ft_strdup(equal + 1);
	}
	else
	{
		node->key = ft_strdup(env_str);
		node->value = ft_strdup("");
	}
	node->next = NULL;
	return (node);
}

t_env	*create_env(char **envp)
{
	t_env	*head;
	t_env	*tmp;
	int		i;

	head = NULL;
	tmp = NULL;
	i = 0;
	while (envp[i])
	{
		t_env *node = create_env_node(envp[i]);
		if (!node)
			return (NULL);
		if (!head)
			head = node;
		else
			tmp->next = node;
		tmp = node;
		i++;
	}
	return (head);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

char	*get_env_value(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	set_env_value(t_env **env, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	/* If not found, add new */
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->key = ft_strdup(key);
	tmp->value = ft_strdup(value);
	tmp->next = *env;
	*env = tmp;
}


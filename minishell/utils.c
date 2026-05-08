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
	// If not found, add new
	tmp = malloc(sizeof(t_env));
	tmp->key = ft_strdup(key);
	tmp->value = ft_strdup(value);
	tmp->next = *env;
	*env = tmp;
}

char	**env_to_array(t_env *env)
{
	int		count;
	char	**array;
	int		i;
	char	*tmp;

	count = 0;
	t_env *tmp_env = env;
	while (tmp_env)
	{
		count++;
		tmp_env = tmp_env->next;
	}
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (env)
	{
		tmp = ft_strjoin(env->key, "=");
		array[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		env = env->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static char	*expand_dollar_var(char *str, t_shell *shell)
{
	char	*dollar_pos;
	char	*var_name;
	char	*var_value;
	char	*result;
	char	*tmp;
	size_t	var_len;

	if (!str || !shell)
		return (ft_strdup(str));
	dollar_pos = ft_strchr(str, '$');
	if (!dollar_pos)
		return (ft_strdup(str));
	var_len = 0;
	while (dollar_pos[var_len + 1] && 
		(ft_isalnum(dollar_pos[var_len + 1]) || dollar_pos[var_len + 1] == '_'))
		var_len++;
	if (var_len == 0)
		return (ft_strdup(str));
	var_name = ft_substr(dollar_pos + 1, 0, var_len);
	var_value = get_env_value(shell->env, var_name);
	if (!var_value)
		var_value = "";
	tmp = ft_substr(str, 0, dollar_pos - str);
	result = ft_strjoin(tmp, var_value);
	if (result && dollar_pos[var_len + 1])
	{
		tmp = result;
		result = ft_strjoin(result, dollar_pos + var_len + 1);
		free(tmp);
	}
	free(var_name);
	free(tmp);
	return (result);
}

char	*expand_variables(char *str, t_shell *shell)
{
	char	*result;
	char	*tmp;

	result = ft_strdup(str);
	while (result && ft_strchr(result, '$'))
	{
		tmp = result;
		result = expand_dollar_var(result, shell);
		if (tmp != str)
			free(tmp);
	}
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_var_value(char *var_name, t_shell *shell)
{
	char	*value;

	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(shell->exit_status));
	value = get_env_value(shell->env, var_name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*append_char(char *s, char c)
{
	char	*new;
	char	buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';
	new = ft_strjoin(s, buffer);
	free(s);
	return (new);
}

static char	*append_str_safe(char *s, const char *add)
{
	char	*new;

	new = ft_strjoin(s, add);
	free(s);
	return (new);
}

char	*expand_input_variables(char *input, t_shell *shell)
{
	char	*result;
	int		i;
	char	*var_name;
	char	*var_value;
	int		var_len;

	result = ft_strdup("");
	if (!result)
		return (ft_strdup(input));
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			result = append_char(result, input[i++]);
			while (input[i] && input[i] != '\'')
				result = append_char(result, input[i++]);
			if (input[i] == '\'')
				result = append_char(result, input[i++]);
		}
		else if (input[i] == '"')
		{
			result = append_char(result, input[i++]);
			while (input[i] && input[i] != '"')
			{
				if (input[i] == '\\' && input[i + 1])
				{
					result = append_char(result, input[i++]);
					result = append_char(result, input[i++]);
				}
				else if (input[i] == '$' && input[i + 1])
				{
					i++;
					if (input[i] == '?')
					{
						var_name = ft_strdup("?");
						i++;
					}
					else
					{
						var_len = 0;
						while (is_var_char(input[i + var_len]))
							var_len++;
						if (var_len == 0)
						{
							result = append_char(result, '$');
							continue ;
						}
						var_name = ft_substr(input + i, 0, var_len);
						i += var_len;
					}
					var_value = get_var_value(var_name, shell);
					result = append_str_safe(result, var_value);
					free(var_name);
					free(var_value);
				}
				else
					result = append_char(result, input[i++]);
			}
			if (input[i] == '"')
				result = append_char(result, input[i++]);
		}
		else if (input[i] == '$' && input[i + 1])
		{
			i++;
			if (input[i] == '?')
			{
				var_name = ft_strdup("?");
				i++;
			}
			else
			{
				var_len = 0;
				while (is_var_char(input[i + var_len]))
					var_len++;
				if (var_len == 0)
				{
					result = append_char(result, '$');
					continue ;
				}
				var_name = ft_substr(input + i, 0, var_len);
				i += var_len;
			}
			var_value = get_var_value(var_name, shell);
			result = append_str_safe(result, var_value);
			free(var_name);
			free(var_value);
		}
		else
			result = append_char(result, input[i++]);
	}
	return (result);
}

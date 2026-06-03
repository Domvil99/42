/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator_start(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == '&');
}

static int	get_operator_len(const char *str)
{
	if (str[0] == '<' && str[1] == '<')
		return (2);
	if (str[0] == '>' && str[1] == '>')
		return (2);
	if (str[0] == '|' && str[1] == '|')
		return (2);
	if (str[0] == '&' && str[1] == '&')
		return (2);
	if (str[0] == '|' || str[0] == '<' || str[0] == '>')
		return (1);
	return (0);
}

static int	count_tokens(const char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (!input[i])
			break ;
		count++;
		if (is_operator_start(input[i]))
			i += get_operator_len(&input[i]);
		else
		{
			while (input[i] && input[i] != ' ' && !is_operator_start(input[i]))
			{
				if (input[i] == '\'')
				{
					i++;
					while (input[i] && input[i] != '\'')
						i++;
					if (input[i] == '\'')
						i++;
				}
				else if (input[i] == '"')
				{
					i++;
					while (input[i] && input[i] != '"')
					{
						if (input[i] == '\\' && input[i + 1])
							i += 2;
						else
							i++;
					}
					if (input[i] == '"')
						i++;
				}
				else
					i++;
			}
		}
	}
	return (count);
}

static char	*copy_token(const char *input, int start, int len)
{
	char	*token;
	int	j;
	int	k;

	token = ft_calloc(len + 1, sizeof(char));
	if (!token)
		return (NULL);
	j = start;
	k = 0;
	while (j < start + len)
	{
		if (input[j] == '\'')
		{
			j++;
			while (j < start + len && input[j] != '\'')
				token[k++] = input[j++];
			if (j < start + len && input[j] == '\'')
				j++;
		}
		else if (input[j] == '"')
		{
			j++;
			while (j < start + len && input[j] != '"')
			{
				if (input[j] == '\\' && j + 1 < start + len)
				{
					token[k++] = input[j++];
					token[k++] = input[j++];
				}
				else
					token[k++] = input[j++];
			}
			if (j < start + len && input[j] == '"')
				j++;
		}
		else
			token[k++] = input[j++];
	}
	token[k] = '\0';
	return (token);
}

char	**tokenize_with_quotes(const char *input)
{
	char	**tokens;
	int	count;
	int	i;
	int	index;
	int	start;
	int	len;

	if (!input || !*input)
		return (ft_calloc(1, sizeof(char *)));
	count = count_tokens(input);
	tokens = ft_calloc(count + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	index = 0;
	while (input[i] && index < count)
	{
		while (input[i] == ' ')
			i++;
		if (!input[i])
			break ;
		if (is_operator_start(input[i]))
		{
			len = get_operator_len(&input[i]);
			tokens[index] = copy_token(input, i, len);
			i += len;
		}
		else
		{
			start = i;
			while (input[i] && input[i] != ' ' && !is_operator_start(input[i]))
			{
				if (input[i] == '\'')
				{
					i++;
					while (input[i] && input[i] != '\'')
						i++;
					if (input[i] == '\'')
						i++;
				}
				else if (input[i] == '"')
				{
					i++;
					while (input[i] && input[i] != '"')
					{
						if (input[i] == '\\' && input[i + 1])
							i += 2;
						else
							i++;
					}
					if (input[i] == '"')
						i++;
				}
				else
					i++;
			}
			len = i - start;
			tokens[index] = copy_token(input, start, len);
		}
		if (!tokens[index])
		{
			free_string_array(tokens);
			return (NULL);
		}
		index++;
	}
	tokens[index] = NULL;
	return (tokens);
}

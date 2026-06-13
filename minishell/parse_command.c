/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	token_is_end(char *token)
{
	return (!token || token[0] == '|' || token[0] == '<'
		|| token[0] == '>' || strcmp(token, "&&") == 0
		|| strcmp(token, "||") == 0);
}

static int	get_arg_count(char **tokens, int idx)
{
	int	count;

	count = 0;
	while (tokens[idx] && !token_is_end(tokens[idx]))
	{
		count++;
		idx++;
	}
	return (count);
}

static char	**copy_args(char **tokens, int idx, int arg_count)
{
	char	**args;
	int	j;

	args = ft_calloc(arg_count + 1, sizeof(char *));
	if (!args)
		return (NULL);
	j = 0;
	while (j < arg_count)
	{
		args[j] = ft_strdup(tokens[idx]);
		j++;
		idx++;
	}
	args[j] = NULL;
	return (args);
}

t_command	*parse_command_args(char **tokens, int *idx)
{
	t_command	*cmd;
	int		arg_count;

	arg_count = get_arg_count(tokens, *idx);
	if (arg_count == 0)
		return (NULL);
	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = copy_args(tokens, *idx, arg_count);
	if (!cmd->args)
	{
		free(cmd);
		return (NULL);
	}
	*idx += arg_count;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->heredoc_delimiter = NULL;
	cmd->heredoc = 0;
	cmd->append = 0;
	cmd->operator_type = 0;
	cmd->next = NULL;
	return (cmd);
}

void	parse_redirection(t_command *cmd, char **tokens, int *idx)
{
	char	*redir_type;
	char	*filename;

	while (tokens[*idx] && (tokens[*idx][0] == '<'
		|| tokens[*idx][0] == '>'))
	{
		redir_type = tokens[*idx];
		(*idx)++;
		if (!tokens[*idx] || tokens[*idx][0] == '|')
			break ;
		filename = tokens[*idx];
		if (strcmp(redir_type, "<") == 0)
		{
			free(cmd->input_file);
			cmd->input_file = ft_strdup(filename);
			cmd->heredoc = 0;
			free(cmd->heredoc_delimiter);
			cmd->heredoc_delimiter = NULL;
		}
		else if (strcmp(redir_type, "<<") == 0)
		{
			free(cmd->heredoc_delimiter);
			cmd->heredoc_delimiter = ft_strdup(filename);
			cmd->heredoc = 1;
			free(cmd->input_file);
			cmd->input_file = NULL;
		}
		else if (strcmp(redir_type, ">") == 0)
		{
			free(cmd->output_file);
			cmd->output_file = ft_strdup(filename);
			cmd->append = 0;
		}
		else if (strcmp(redir_type, ">>") == 0)
		{
			free(cmd->output_file);
			cmd->output_file = ft_strdup(filename);
			cmd->append = 1;
		}
		(*idx)++;
	}
}

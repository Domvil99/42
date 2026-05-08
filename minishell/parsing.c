/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:30:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command	*parse_command_args(char **tokens, int *idx)
{
	t_command	*cmd;
	char		**args;
	int			arg_count;
	int			i;
	int			j;

	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		return (NULL);
	arg_count = 0;
	i = *idx;
	while (tokens[i] && tokens[i][0] != '|' && tokens[i][0] != '<' 
		&& tokens[i][0] != '>')
	{
		arg_count++;
		i++;
	}
	if (arg_count == 0)
		return (NULL);
	args = ft_calloc(arg_count + 1, sizeof(char *));
	if (!args)
		return (free(cmd), NULL);
	j = 0;
	i = *idx;
	while (tokens[i] && tokens[i][0] != '|' && tokens[i][0] != '<' 
		&& tokens[i][0] != '>')
	{
		args[j] = ft_strdup(tokens[i]);
		j++;
		i++;
	}
	args[j] = NULL;
	cmd->args = args;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->append = 0;
	cmd->next = NULL;
	*idx = i;
	return (cmd);
}

static void	parse_redirection(t_command *cmd, char **tokens, int *idx)
{
	char	*redir_type;
	char	*filename;

	while (tokens[*idx] && (tokens[*idx][0] == '<' || tokens[*idx][0] == '>'))
	{
		redir_type = tokens[*idx];
		(*idx)++;
		if (!tokens[*idx] || tokens[*idx][0] == '|')
			break ;
		filename = tokens[*idx];
		if (ft_strcmp(redir_type, "<") == 0)
			cmd->input_file = ft_strdup(filename);
		else if (ft_strcmp(redir_type, ">") == 0)
		{
			free(cmd->output_file);
			cmd->output_file = ft_strdup(filename);
			cmd->append = 0;
		}
		else if (ft_strcmp(redir_type, ">>") == 0)
		{
			free(cmd->output_file);
			cmd->output_file = ft_strdup(filename);
			cmd->append = 1;
		}
		(*idx)++;
	}
}

t_command	*parse_input(char *input)
{
	char		**tokens;
	t_command	*head;
	t_command	*current;
	int			i;

	if (!input || !*input)
		return (NULL);
	tokens = ft_split(input, ' ');
	if (!tokens)
		return (NULL);
	head = NULL;
	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "|") == 0)
		{
			i++;
			continue ;
		}
		current = parse_command_args(tokens, &i);
		if (!current)
			break ;
		parse_redirection(current, tokens, &i);
		if (!head)
			head = current;
		else
		{
			t_command *tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = current;
		}
	}
	free(tokens);
	return (head);
}

void	free_commands(t_command *cmd)
{
	t_command	*tmp;
	int			i;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
		}
		free(cmd->input_file);
		free(cmd->output_file);
		free(cmd);
		cmd = tmp;
	}
}

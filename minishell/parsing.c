#include "minishell.h"

static int	validate_input(const char *input)
{
	char	quote;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
				return (-1);
			i++;
		}
		else if (input[i] == ';')
			return (-1);
		else if (input[i] == '\\')
		{
			if (!input[i + 1])
				return (-1);
			i += 2;
			continue ;
		}
		else
			i++;
	}
	return (0);
}

static void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	is_control_token(const char *token)
{
	if (!token)
		return (0);
	if (strcmp(token, "|") == 0)
		return (1);
	if (strcmp(token, "&&") == 0)
		return (1);
	if (strcmp(token, "||") == 0)
		return (1);
	return (0);
}

static int	is_redirection(const char *token)
{
	return (strcmp(token, "<") == 0 || strcmp(token, "<<") == 0
		|| strcmp(token, ">") == 0 || strcmp(token, ">>") == 0);
}

static t_command	*allocate_command(void)
{
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->heredoc_delimiter = NULL;
	cmd->heredoc = 0;
	cmd->append = 0;
	cmd->operator_type = 0;
	cmd->next = NULL;
	return (cmd);
}

static void	apply_redirection(t_command *cmd, char **tokens, int *idx)
{
	char	*redir;

	redir = tokens[*idx];
	(*idx)++;
	if (!tokens[*idx] || is_control_token(tokens[*idx]))
		return ;
	if (strcmp(redir, "<") == 0)
	{
		free(cmd->input_file);
		cmd->input_file = ft_strdup(tokens[*idx]);
		cmd->heredoc = 0;
		free(cmd->heredoc_delimiter);
		cmd->heredoc_delimiter = NULL;
	}
	else if (strcmp(redir, "<<") == 0)
	{
		free(cmd->heredoc_delimiter);
		cmd->heredoc_delimiter = ft_strdup(tokens[*idx]);
		cmd->heredoc = 1;
		free(cmd->input_file);
		cmd->input_file = NULL;
	}
	else if (strcmp(redir, ">") == 0)
	{
		free(cmd->output_file);
		cmd->output_file = ft_strdup(tokens[*idx]);
		cmd->append = 0;
	}
	else if (strcmp(redir, ">>") == 0)
	{
		free(cmd->output_file);
		cmd->output_file = ft_strdup(tokens[*idx]);
		cmd->append = 1;
	}
	(*idx)++;
}

static int	get_operator_type(const char *token)
{
	if (strcmp(token, "|") == 0)
		return (1);
	if (strcmp(token, "&&") == 0)
		return (2);
	if (strcmp(token, "||") == 0)
		return (3);
	return (0);
}

static t_command	*parse_command_args(char **tokens, int *idx)
{
	t_command	*cmd;
	int		count;
	int		i;
	int		arg_index;

	count = 0;
	i = *idx;
	while (tokens[i] && !is_control_token(tokens[i]))
	{
		if (is_redirection(tokens[i]))
			i += 2;
		else
		{
			count++;
			i++;
		}
	}
	cmd = allocate_command();
	if (!cmd)
		return (NULL);
	cmd->args = ft_calloc(count + 1, sizeof(char *));
	if (!cmd->args)
	{
		free(cmd);
		return (NULL);
	}
	arg_index = 0;
	while (tokens[*idx] && !is_control_token(tokens[*idx]))
	{
		if (is_redirection(tokens[*idx]))
		{
			apply_redirection(cmd, tokens, idx);
			continue ;
		}
		cmd->args[arg_index] = ft_strdup(tokens[*idx]);
		if (!cmd->args[arg_index])
		{
			free_commands(cmd);
			return (NULL);
		}
		arg_index++;
		(*idx)++;
	}
	cmd->args[arg_index] = NULL;
	return (cmd);
}

static t_command	*append_command(t_command *head, t_command *cmd)
{
	t_command	*last;

	if (!head)
		return (cmd);
	last = head;
	while (last->next)
		last = last->next;
	last->next = cmd;
	return (head);
}

void	free_commands(t_command *head)
{
	t_command	*tmp;
	int		idx;

	while (head)
	{
		tmp = head->next;
		idx = 0;
		while (head->args && head->args[idx])
		{
			free(head->args[idx]);
			idx++;
		}
		free(head->args);
		free(head->input_file);
		free(head->output_file);
		free(head->heredoc_delimiter);
		free(head);
		head = tmp;
	}
}

t_command	*parse_input(char *input, t_shell *shell)
{
	char		**tokens;
	char		*expanded_input;
	t_command	*head;
	t_command	*last;
	t_command	*command;
	int		idx;

	if (!input || validate_input(input) < 0)
		return (NULL);
	expanded_input = expand_input_variables(input, shell);
	if (!expanded_input)
		return (NULL);
	tokens = tokenize_with_quotes(expanded_input);
	free(expanded_input);
	if (!tokens)
		return (NULL);
	head = NULL;
	last = NULL;
	idx = 0;
	while (tokens[idx])
	{
		if (is_control_token(tokens[idx]))
		{
			if (last)
				last->operator_type = get_operator_type(tokens[idx]);
			idx++;
			continue ;
		}
		command = parse_command_args(tokens, &idx);
		if (!command)
		{
			free_commands(head);
			free_tokens(tokens);
			return (NULL);
		}
		head = append_command(head, command);
		if (!last)
			last = head;
		else
			last = last->next;
	}
	free_tokens(tokens);
	return (head);
}

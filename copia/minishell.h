/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil <domvil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:00:00 by domvil            #+#    #+#             */
/*   Updated: 2026/05/08 10:00:00 by domvil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>

typedef struct s_command
{
	char	**args;
	char	*input_file;
	char	*output_file;
	int		append;
	struct s_command *next;
}	t_command;

typedef struct s_env
{
	char	*key;
	char	*value;
	struct s_env *next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
	char	*pwd;
	char	*oldpwd;
	int		exit_status;
}	t_shell;

// Parsing
t_command	*parse_input(char *input);
void		free_commands(t_command *cmd);

// Builtins
int			ft_cd(t_shell *shell, char **args);
int			ft_echo(char **args);
int			ft_pwd(t_shell *shell);
int			ft_export(t_shell *shell, char **args);
int			ft_unset(t_shell *shell, char **args);
int			ft_env(t_shell *shell);
int			ft_exit(t_shell *shell, char **args);

// Execution
void		execute_commands(t_shell *shell, t_command *cmd);
void		execute_builtin(t_shell *shell, t_command *cmd);
void		execute_external(t_shell *shell, t_command *cmd);
char		*resolve_executable_path(t_shell *shell, char *cmd);

// Signals
void		setup_signals(void);

// Utils
t_env		*create_env(char **envp);
void		free_env(t_env *env);
char		*get_env_value(t_env *env, char *key);
void		set_env_value(t_env **env, char *key, char *value);
char		**env_to_array(t_env *env);
int			ft_strcmp(const char *s1, const char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:12:31 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:12:31 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define MT_SIG_ONE SIGUSR1
# define MT_SIG_ZERO SIGUSR2
# define MT_BIT_DELAY_US 900

typedef struct s_server_state
{
	int			current_char;
	int			bit_index;
	int			active_client;
}	t_server_state;

int		mt_parse_pid(const char *str, pid_t *pid_out);
int		mt_send_char(pid_t server_pid, unsigned char c);
int		mt_send_message(pid_t server_pid, const char *msg);
void	mt_write_error(const char *msg);

#endif

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

# define FT_SIGCOMM_BIT_ONE SIGUSR1
# define FT_SIGCOMM_BIT_ZERO SIGUSR2
# define FT_SIGCOMM_DELAY_US 900

typedef struct s_sigcomm_state
{
	int			current_byte;
	int			bit_index;
	int			client_pid;
}	t_sigcomm_state;

int		ft_parse_pid(const char *str, pid_t *pid_out);
int		ft_sigcomm_send_byte(pid_t server_pid, unsigned char byte);
int		ft_sigcomm_send_string(pid_t server_pid, const char *msg);
void	ft_write_error(const char *msg);

#endif

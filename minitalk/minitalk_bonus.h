/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:27:19 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:27:19 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "minitalk.h"

int	ft_sigcomm_send_byte_ack(pid_t server_pid, unsigned char byte,
		volatile sig_atomic_t *ack_received);
int	ft_sigcomm_send_string_ack(pid_t server_pid, const char *msg,
		volatile sig_atomic_t *ack_received);

#endif

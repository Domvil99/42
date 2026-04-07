/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:37:54 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:37:54 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_sigcomm_send_byte_ack(pid_t server_pid, unsigned char byte,
		volatile sig_atomic_t *ack_received)
{
	int	bit_index;
	int	sig;

	bit_index = 7;
	while (bit_index >= 0)
	{
		*ack_received = 0;
		if ((byte >> bit_index) & 1)
			sig = FT_SIGCOMM_BIT_ONE;
		else
			sig = FT_SIGCOMM_BIT_ZERO;
		if (kill(server_pid, sig) == -1)
			return (0);
		while (!(*ack_received))
			pause();
		bit_index--;
	}
	return (1);
}

int	ft_sigcomm_send_string_ack(pid_t server_pid, const char *msg,
		volatile sig_atomic_t *ack_received)
{
	size_t	idx;

	if (!msg)
		return (0);
	idx = 0;
	while (msg[idx])
	{
		if (!ft_sigcomm_send_byte_ack(server_pid,
				(unsigned char)msg[idx], ack_received))
			return (0);
		idx++;
	}
	if (!ft_sigcomm_send_byte_ack(server_pid, '\0', ack_received))
		return (0);
	return (1);
}

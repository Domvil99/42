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

int	mt_bonus_send_char(pid_t server_pid, unsigned char c,
		volatile sig_atomic_t *ack_flag)
{
	int	bit;
	int	sig;

	bit = 7;
	while (bit >= 0)
	{
		*ack_flag = 0;
		if ((c >> bit) & 1)
			sig = MT_SIG_ONE;
		else
			sig = MT_SIG_ZERO;
		if (kill(server_pid, sig) == -1)
			return (0);
		while (!(*ack_flag))
			pause();
		bit--;
	}
	return (1);
}

int	mt_bonus_send_message(pid_t server_pid, const char *msg,
		volatile sig_atomic_t *ack_flag)
{
	size_t	idx;

	if (!msg)
		return (0);
	idx = 0;
	while (msg[idx])
	{
		if (!mt_bonus_send_char(server_pid, (unsigned char)msg[idx], ack_flag))
			return (0);
		idx++;
	}
	if (!mt_bonus_send_char(server_pid, '\0', ack_flag))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:24:27 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:24:27 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mt_send_char(pid_t server_pid, unsigned char c)
{
	int	bit;
	int	sig;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			sig = MT_SIG_ONE;
		else
			sig = MT_SIG_ZERO;
		if (kill(server_pid, sig) == -1)
			return (0);
		usleep(MT_BIT_DELAY_US);
		bit--;
	}
	return (1);
}

int	mt_send_message(pid_t server_pid, const char *msg)
{
	size_t	idx;

	if (!msg)
		return (0);
	idx = 0;
	while (msg[idx])
	{
		if (!mt_send_char(server_pid, (unsigned char)msg[idx]))
			return (0);
		idx++;
	}
	if (!mt_send_char(server_pid, '\0'))
		return (0);
	return (1);
}

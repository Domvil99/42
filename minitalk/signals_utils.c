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

int	ft_sigcomm_send_byte(pid_t server_pid, unsigned char byte)
{
	int	bit_index;
	int	sig;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((byte >> bit_index) & 1)
			sig = FT_SIGCOMM_BIT_ONE;
		else
			sig = FT_SIGCOMM_BIT_ZERO;
		if (kill(server_pid, sig) == -1)
			return (0);
		usleep(FT_SIGCOMM_DELAY_US);
		bit_index--;
	}
	return (1);
}

int	ft_sigcomm_send_string(pid_t server_pid, const char *msg)
{
	size_t	idx;

	if (!msg)
		return (0);
	idx = 0;
	while (msg[idx])
	{
		if (!ft_sigcomm_send_byte(server_pid, (unsigned char)msg[idx]))
			return (0);
		idx++;
	}
	if (!ft_sigcomm_send_byte(server_pid, '\0'))
		return (0);
	return (1);
}

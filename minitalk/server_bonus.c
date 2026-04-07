/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:28:11 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:28:11 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_sigcomm_state	g_server_state;

static void	reset_state(pid_t client_pid)
{
	g_server_state.current_byte = 0;
	g_server_state.bit_index = 0;
	g_server_state.client_pid = client_pid;
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server_state.client_pid != info->si_pid)
		reset_state(info->si_pid);
	if (sig == FT_SIGCOMM_BIT_ONE)
		g_server_state.current_byte |= (1 << (7 - g_server_state.bit_index));
	g_server_state.bit_index++;
	if (g_server_state.bit_index == 8)
	{
		if (g_server_state.current_byte == '\0')
		{
			write(1, "\n", 1);
			reset_state(0);
		}
		else
		{
			write(1, &g_server_state.current_byte, 1);
			reset_state(info->si_pid);
		}
	}
	if (kill(info->si_pid, FT_SIGCOMM_BIT_ONE) == -1)
		return ;
}

static int	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(FT_SIGCOMM_BIT_ONE, &sa, NULL) == -1)
		return (0);
	if (sigaction(FT_SIGCOMM_BIT_ZERO, &sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(void)
{
	ft_putstr_fd("Server bonus PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	reset_state(0);
	if (!setup_signals())
	{
		ft_write_error("Error: failed to configure signal handlers\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}

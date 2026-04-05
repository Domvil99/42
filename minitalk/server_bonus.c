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

/* Needed to persist bit assembly state across async signal callbacks. */
static t_server_state	g_server_state;

static void	reset_state(pid_t client_pid)
{
	g_server_state.current_char = 0;
	g_server_state.bit_index = 0;
	g_server_state.active_client = client_pid;
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server_state.active_client != info->si_pid)
		reset_state(info->si_pid);
	if (sig == MT_SIG_ONE)
		g_server_state.current_char |= (1 << (7 - g_server_state.bit_index));
	g_server_state.bit_index++;
	if (kill(info->si_pid, MT_SIG_ONE) == -1)
		return ;
	if (g_server_state.bit_index == 8)
	{
		if (g_server_state.current_char == '\0')
		{
			write(1, "\n", 1);
			reset_state(0);
		}
		else
		{
			write(1, &g_server_state.current_char, 1);
			reset_state(info->si_pid);
		}
	}
}

static int	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(MT_SIG_ONE, &sa, NULL) == -1)
		return (0);
	if (sigaction(MT_SIG_ZERO, &sa, NULL) == -1)
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
		mt_write_error("Error: failed to configure signal handlers\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}

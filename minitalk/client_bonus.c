/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:29:22 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:29:22 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_ack_received;

static int	validate_args(int argc, char **argv, pid_t *server_pid)
{
	if (argc != 3)
	{
		ft_write_error("Usage: ./client_bonus <server_pid> <message>\n");
		return (0);
	}
	if (!ft_parse_pid(argv[1], server_pid))
	{
		ft_write_error("Error: invalid server PID\n");
		return (0);
	}
	return (1);
}

static void	handle_ack(int sig)
{
	if (sig == FT_SIGCOMM_BIT_ONE)
		g_ack_received = 1;
}

static int	setup_ack_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(FT_SIGCOMM_BIT_ONE, &sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (!validate_args(argc, argv, &server_pid))
		return (1);
	if (!setup_ack_handler())
	{
		ft_write_error("Error: failed to configure ACK handler\n");
		return (1);
	}
	if (!ft_sigcomm_send_string_ack(server_pid, argv[2], &g_ack_received))
	{
		ft_write_error("Error: failed to send message\n");
		return (1);
	}
	return (0);
}

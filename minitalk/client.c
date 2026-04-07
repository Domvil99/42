/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:14:49 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:14:49 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	validate_args(int argc, char **argv, pid_t *server_pid)
{
	if (argc != 3)
	{
		ft_write_error("Usage: ./client <server_pid> <message>\n");
		return (0);
	}
	if (!ft_parse_pid(argv[1], server_pid))
	{
		ft_write_error("Error: invalid server PID\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (!validate_args(argc, argv, &server_pid))
		return (1);
	if (!ft_sigcomm_send_string(server_pid, argv[2]))
	{
		ft_write_error("Error: failed to send message\n");
		return (1);
	}
	return (0);
}

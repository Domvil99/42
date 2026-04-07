/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:22:15 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:22:15 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_parse_pid(const char *str, pid_t *pid_out)
{
	long	value;
	int		idx;

	if (!str || !str[0])
		return (0);
	idx = 0;
	value = 0;
	while (str[idx])
	{
		if (!ft_isdigit((unsigned char)str[idx]))
			return (0);
		value = (value * 10) + (str[idx] - '0');
		if (value > INT_MAX)
			return (0);
		idx++;
	}
	if (value <= 0)
		return (0);
	*pid_out = (pid_t)value;
	return (1);
}

void	ft_write_error(const char *msg)
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);
}

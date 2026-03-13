/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 19:40:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_overflow(long value, int sign)
{
	if (sign == 1 && value > INT_MAX)
		return (1);
	if (sign == -1 && (-value) < INT_MIN)
		return (1);
	return (0);
}

int	is_valid_number(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ps_atol(const char *s, int *ok)
{
	long	value;
	int		sign;
	int		i;

	value = 0;
	sign = 1;
	i = 0;
	*ok = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		value = value * 10 + (s[i] - '0');
		if (is_overflow(value, sign))
		{
			*ok = 0;
			return (0);
		}
		i++;
	}
	return (value * sign);
}

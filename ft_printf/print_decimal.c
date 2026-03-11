/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int		count;
	long	value;

	value = n;
	if (value <= 0)
	{
		count = 1;
		value = -value;
	}
	else
		count = 0;
	while (value)
	{
		value /= 10;
		count++;
	}
	return (count);
}

int	print_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (count_digits(n));
}

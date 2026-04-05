/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:56:14 by saospina           #+#    #+#            */
/*   Updated: 2025/10/21 16:08:27 by saospina          ###   ########.fr      */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	put_hex(unsigned int n, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, upper);
	write(1, &base[n % 16], 1);
}

static int	count_digits_hex(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	set_hex_values(unsigned int n, t_format f, int values[4])
{
	values[0] = count_digits_hex(n);
	if (f.has_precision && f.precision == 0 && n == 0)
		values[0] = 0;
	values[1] = 0;
	if (f.has_precision && f.precision > values[0])
		values[1] = f.precision - values[0];
	values[2] = 0;
	if (f.hash && n != 0)
		values[2] = 2;
	values[3] = f.width - (values[0] + values[1] + values[2]);
	if (values[3] < 0)
		values[3] = 0;
}

static void	put_repeat(char c, int count)
{
	while (count-- > 0)
		write(1, &c, 1);
}

int	print_hex(va_list args, t_format f)
{
	unsigned int	n;
	int				values[4];

	n = va_arg(args, unsigned int);
	set_hex_values(n, f, values);
	if (!f.left_align && (!f.zero_pad || f.has_precision))
		put_repeat(' ', values[3]);
	if (values[2] && f.type == 'x')
		write(1, "0x", 2);
	if (values[2] && f.type == 'X')
		write(1, "0X", 2);
	if (!f.left_align && f.zero_pad && !f.has_precision)
		put_repeat('0', values[3]);
	put_repeat('0', values[1]);
	if (values[0] > 0 && f.type == 'X')
		put_hex(n, 1);
	if (values[0] > 0 && f.type == 'x')
		put_hex(n, 0);
	if (f.left_align)
		put_repeat(' ', values[3]);
	if (f.width > values[0] + values[1] + values[2])
		return (f.width);
	return (values[0] + values[1] + values[2]);
}

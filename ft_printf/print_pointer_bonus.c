/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_ptr(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_ptr(n / 16);
	write(1, &base[n % 16], 1);
}

static int	count_digits_ptr(unsigned long n)
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

static int	write_padding(int padding)
{
	int	printed;

	printed = 0;
	while (padding-- > 0)
		printed += write(1, " ", 1);
	return (printed);
}

static int	print_nil(t_format f)
{
	int	padding;
	int	printed;

	padding = 0;
	if (f.width > 5)
		padding = f.width - 5;
	printed = 0;
	if (!f.left_align)
		printed += write_padding(padding);
	printed += write(1, "(nil)", 5);
	if (f.left_align)
		printed += write_padding(padding);
	return (printed);
}

int	print_pointer(va_list args, t_format f)
{
	unsigned long	ptr;
	int				digits;
	int				total_len;
	int				padding;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (print_nil(f));
	digits = count_digits_ptr(ptr);
	total_len = digits + 2;
	padding = 0;
	if (f.width > total_len)
		padding = f.width - total_len;
	if (!f.left_align)
		write_padding(padding);
	write(1, "0x", 2);
	put_ptr(ptr);
	if (f.left_align)
		write_padding(padding);
	if (f.width > total_len)
		return (f.width);
	return (total_len);
}

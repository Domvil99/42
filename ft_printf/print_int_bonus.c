/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	write_padding(int count, char c)
{
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}
}

static int	get_sign_char(int n, t_format f)
{
	if (n < 0)
		return ('-');
	if (f.plus)
		return ('+');
	if (f.space)
		return (' ');
	return (0);
}

static int	load_number_data(int n, t_int_data *d)
{
	d->raw = ft_itoa(n);
	if (!d->raw)
		return (0);
	d->num = d->raw;
	if (n < 0)
		d->num = d->raw + 1;
	d->num_len = ft_strlen(d->num);
	return (1);
}

static void	compute_padding(int n, t_format f, t_int_data *d)
{
	d->sign_char = get_sign_char(n, f);
	d->sign_len = 0;
	if (d->sign_char)
		d->sign_len = 1;
	if (f.has_precision && f.precision == 0 && n == 0)
		d->num_len = 0;
	d->zero_pad = 0;
	if (f.has_precision && f.precision > d->num_len)
		d->zero_pad = f.precision - d->num_len;
	else if (!f.has_precision && f.zero_pad && !f.left_align)
	{
		if (f.width > d->num_len + d->sign_len)
			d->zero_pad = f.width - d->num_len - d->sign_len;
	}
	d->full_len = d->num_len + d->zero_pad + d->sign_len;
	d->space_pad = 0;
	if (f.width > d->full_len)
		d->space_pad = f.width - d->full_len;
}

int	print_int(va_list args, t_format f)
{
	int			n;
	t_int_data	d;

	n = va_arg(args, int);
	if (!load_number_data(n, &d))
		return (0);
	compute_padding(n, f, &d);
	if (!f.left_align)
		write_padding(d.space_pad, ' ');
	if (d.sign_char)
		write(1, &d.sign_char, 1);
	write_padding(d.zero_pad, '0');
	if (d.num_len > 0)
		write(1, d.num, d.num_len);
	if (f.left_align)
		write_padding(d.space_pad, ' ');
	free(d.raw);
	return (d.full_len + d.space_pad);
}

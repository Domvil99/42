/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_format(const char *format, va_list args, int *i)
{
	t_format	f;
	int			len;
	int			consumed;

	len = 0;
	consumed = parse_format(format, &f);
	if (consumed > 0)
		*i += consumed - 1;
	if (f.type == 'c')
		len += print_char(args, f);
	else if (f.type == 's')
		len += print_str(args, f);
	else if (f.type == 'd' || f.type == 'i')
		len += print_int(args, f);
	else if (f.type == 'u')
		len += print_unsigned(args, f);
	else if (f.type == 'x' || f.type == 'X')
		len += print_hex(args, f);
	else if (f.type == 'p')
		len += print_pointer(args, f);
	else if (f.type == '%')
		len += write(1, "%", 1);
	return (len);
}

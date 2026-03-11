/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(const char format, va_list args)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 's')
		return (print_string(va_arg(args, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (print_decimal(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += dispatch(format[++i], args);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

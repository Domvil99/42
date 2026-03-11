/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	write_padding(int padding)
{
	while (padding-- > 0)
		write(1, " ", 1);
}

int	print_str(va_list args, t_format f)
{
	char	*str;
	int		len;
	int		padding;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f.has_precision && f.precision < len)
		len = f.precision;
	padding = 0;
	if (f.width > len)
		padding = f.width - len;
	if (!f.left_align)
		write_padding(padding);
	write(1, str, len);
	if (f.left_align)
		write_padding(padding);
	if (f.width > len)
		return (f.width);
	return (len);
}

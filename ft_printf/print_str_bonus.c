/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

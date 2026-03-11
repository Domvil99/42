/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(va_list args, t_format f)
{
	char	c;
	int		padding;
	int		len;

	c = (char)va_arg(args, int);
	len = 1;
	padding = 0;
	if (f.width > 1)
		padding = f.width - 1;
	if (!f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);
	write(1, &c, 1);
	if (f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);
	if (f.width > 1)
		return (len + f.width - 1);
	return (len);
}

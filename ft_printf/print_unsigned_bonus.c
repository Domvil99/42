/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_utoa(unsigned int n)
{
	int				len;
	unsigned int	tmp;
	char			*str;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

static void	print_padding(int count, char c)
{
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}
}

static void	get_padding(t_format f, int num_len, int *zero_pad, int *space_pad)
{
	*zero_pad = 0;
	if (f.has_precision && f.precision > num_len)
		*zero_pad = f.precision - num_len;
	else if (!f.has_precision && f.zero_pad
		&& !f.left_align && f.width > num_len)
		*zero_pad = f.width - num_len;
	*space_pad = 0;
	if (f.width > num_len + *zero_pad)
		*space_pad = f.width - (num_len + *zero_pad);
}

static int	init_unsigned(va_list args, t_format f, char **str, int *num_len)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	*str = ft_utoa(n);
	if (!*str)
		return (0);
	*num_len = ft_strlen(*str);
	if (f.has_precision && f.precision == 0 && n == 0)
	{
		free(*str);
		*str = NULL;
		*num_len = 0;
	}
	return (1);
}

int	print_unsigned(va_list args, t_format f)
{
	char			*str;
	int				num_len;
	int				zero_pad;
	int				space_pad;

	if (!init_unsigned(args, f, &str, &num_len))
		return (0);
	get_padding(f, num_len, &zero_pad, &space_pad);
	if (!f.left_align)
		print_padding(space_pad, ' ');
	print_padding(zero_pad, '0');
	if (num_len > 0 && str)
		write(1, str, num_len);
	if (f.left_align)
		print_padding(space_pad, ' ');
	free(str);
	return (num_len + zero_pad + space_pad);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	is_flag(char c)
{
	return (ft_strchr("-0+ #", c) != NULL);
}

static int	is_type(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

static int	parse_flags(const char *format, t_format *f)
{
	int	i;

	i = 0;
	while (is_flag(format[i]))
	{
		if (format[i] == '-')
			f->left_align = 1;
		else if (format[i] == '0')
			f->zero_pad = 1;
		else if (format[i] == '+')
			f->plus = 1;
		else if (format[i] == ' ')
			f->space = 1;
		else if (format[i] == '#')
			f->hash = 1;
		i++;
	}
	return (i);
}

static int	parse_width_precision(const char *format, t_format *f)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
	{
		f->width = f->width * 10 + (format[i] - '0');
		i++;
	}
	if (format[i] == '.')
	{
		f->has_precision = 1;
		i++;
		while (ft_isdigit(format[i]))
		{
			f->precision = f->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

int	parse_format(const char *format, t_format *f)
{
	int	i;

	i = 0;
	ft_bzero(f, sizeof(t_format));
	i += parse_flags(format + i, f);
	i += parse_width_precision(format + i, f);
	if (is_type(format[i]))
	{
		f->type = format[i];
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:25:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 22:46:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *s, int *ok)
{
	double	sign;
	double	value;
	double	frac;

	sign = 1.0;
	value = 0.0;
	frac = 0.1;
	if (*s == '-' || *s == '+')
		sign = 1.0 - 2.0 * (*s++ == '-');
	if (!ft_isdigit(*s) && *s != '.')
		return (*ok = 0, 0.0);
	while (ft_isdigit(*s))
		value = value * 10.0 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
	{
		value += (*s++ - '0') * frac;
		frac *= 0.1;
	}
	*ok = (*s == '\0');
	return (value * sign);
}

void	print_usage(void)
{
	ft_printf("Usage:\n"
		"  ./fractol mandelbrot\n"
		"  ./fractol julia <real> <imag>\n"
		"Controls:\n"
		"  ESC: exit\n"
		"  Mouse wheel: zoom\n"
		"  C: change palette\n");
}

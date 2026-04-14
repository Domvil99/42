/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:07:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 18:07:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mandelbrot_iter_bonus(t_complex_bonus c, int max_iter)
{
	t_complex_bonus	z;
	double			tmp;
	int				i;

	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (i < max_iter && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

int	julia_iter_bonus(t_complex_bonus z, t_complex_bonus c, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < max_iter && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

int	burning_ship_iter_bonus(t_complex_bonus c, int max_iter)
{
	t_complex_bonus	z;
	double			tmp;
	int				i;

	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (i < max_iter && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = fabs(2.0 * z.re * z.im) + c.im;
		z.re = fabs(tmp);
		i++;
	}
	return (i);
}

int	color_from_iter_bonus(int iter, int max_iter, int shift)
{
	int	r;
	int	g;
	int	b;

	if (iter >= max_iter)
		return (0x000000);
	r = (iter * 11 + shift) % 255;
	g = (iter * 5 + shift * 3) % 255;
	b = (iter * 17 + shift * 2) % 255;
	return ((r << 16) | (g << 8) | b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:06:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 18:06:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_same_bonus(const char *a, const char *b)
{
	return (ft_strncmp(a, b, ft_strlen(b) + 1) == 0);
}

static int	parse_julia_bonus(t_app_bonus *app, int argc, char **argv)
{
	int	ok_re;
	int	ok_im;

	if (argc != 4)
		return (0);
	ok_re = 0;
	ok_im = 0;
	app->fractal = FRACTAL_JULIA;
	app->julia_c.re = ft_atod_bonus(argv[2], &ok_re);
	app->julia_c.im = ft_atod_bonus(argv[3], &ok_im);
	return (ok_re && ok_im);
}

int	parse_args_bonus(t_app_bonus *app, int argc, char **argv)
{
	if (argc < 2)
		return (print_usage_bonus(), 0);
	if (is_same_bonus(argv[1], "mandelbrot") && argc == 2)
		return (app->fractal = FRACTAL_MANDELBROT, 1);
	if (is_same_bonus(argv[1], "burningship") && argc == 2)
		return (app->fractal = FRACTAL_BURNING_SHIP, 1);
	if (is_same_bonus(argv[1], "julia") && parse_julia_bonus(app, argc, argv))
		return (1);
	return (print_usage_bonus(), 0);
}

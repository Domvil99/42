/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:21:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 17:21:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_same(const char *a, const char *b)
{
	return (ft_strncmp(a, b, ft_strlen(b) + 1) == 0);
}

static int	parse_julia(t_app *app, int argc, char **argv)
{
	int	ok_re;
	int	ok_im;

	if (argc != 4)
		return (0);
	ok_re = 0; //debo de preguntar 
	ok_im = 0;
	app->fractal = FRACTAL_JULIA;
	app->julia_c.re = ft_atod(argv[2], &ok_re);
	app->julia_c.im = ft_atod(argv[3], &ok_im);
	return (ok_re && ok_im);
}

int	parse_args(t_app *app, int argc, char **argv)
{
	if (argc < 2)
		return (print_usage(), 0);
	if (is_same(argv[1], "mandelbrot") && argc == 2)
	{
		app->fractal = FRACTAL_MANDELBROT;
		app->julia_c.re = 0.0; //debo de preguntar
		app->julia_c.im = 0.0;
		return (1);
	}
	if (is_same(argv[1], "julia") && parse_julia(app, argc, argv))
		return (1);
	return (print_usage(), 0);
}

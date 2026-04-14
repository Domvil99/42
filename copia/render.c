/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:23:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 17:23:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_complex	pixel_to_complex(t_app *app, int x, int y)
{
	t_complex	p;
	double		range_re;
	double		range_im;

	range_re = app->view.max_re - app->view.min_re;
	range_im = app->view.max_im - app->view.min_im;
	p.re = app->view.min_re + (double)x * (range_re / (WIDTH - 1));
	p.im = app->view.max_im - (double)y * (range_im / (HEIGHT - 1));
	return (p);
}

void	render_fractal(t_app *app)
{
	int			x;
	int			y;
	int			iter;
	t_complex	p;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			p = pixel_to_complex(app, x, y);
			if (app->fractal == FRACTAL_MANDELBROT)
				iter = mandelbrot_iter(p, app->max_iter);
			else
				iter = julia_iter(p, app->julia_c, app->max_iter);
			put_pixel(&app->img, x, y,
				color_from_iter(iter, app->max_iter, app->palette_shift));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.ptr, 0, 0);
}

void	zoom_view(t_app *app, double factor, int x, int y)
{
	double	center_re;
	double	center_im;
	double	half_re;
	double	half_im;

	center_re = app->view.min_re
		+ (double)x * (app->view.max_re - app->view.min_re) / (WIDTH - 1);
	center_im = app->view.max_im
		- (double)y * (app->view.max_im - app->view.min_im) / (HEIGHT - 1);
	half_re = (app->view.max_re - app->view.min_re) * factor / 2.0;
	half_im = (app->view.max_im - app->view.min_im) * factor / 2.0;
	app->view.min_re = center_re - half_re;
	app->view.max_re = center_re + half_re;
	app->view.min_im = center_im - half_im;
	app->view.max_im = center_im + half_im;
}

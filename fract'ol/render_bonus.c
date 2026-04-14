/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:08:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 21:09:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	put_pixel_bonus(t_img_bonus *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_complex_bonus	pix_to_cplx_bonus(t_app_bonus *app, int x, int y)
{
	t_complex_bonus	p;
	double			range_re;
	double			range_im;

	range_re = app->view.max_re - app->view.min_re;
	range_im = app->view.max_im - app->view.min_im;
	p.re = app->view.min_re + (double)x * (range_re / (WIDTH - 1));
	p.im = app->view.max_im - (double)y * (range_im / (HEIGHT - 1));
	return (p);
}

static int	iter_for_pixel_bonus(t_app_bonus *app, t_complex_bonus p)
{
	if (app->fractal == FRACTAL_MANDELBROT)
		return (mandelbrot_iter_bonus(p, app->max_iter));
	if (app->fractal == FRACTAL_BURNING_SHIP)
		return (burning_ship_iter_bonus(p, app->max_iter));
	return (julia_iter_bonus(p, app->julia_c, app->max_iter));
}

void	render_fractal_bonus(t_app_bonus *app)
{
	int				x;
	int				y;
	int				iter;
	t_complex_bonus	p;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			p = pix_to_cplx_bonus(app, x, y);
			iter = iter_for_pixel_bonus(app, p);
			put_pixel_bonus(&app->img, x, y,
				color_from_iter_bonus(iter, app->max_iter, app->palette_shift));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.ptr, 0, 0);
}

void	zoom_view_bonus(t_app_bonus *app, double factor, int x, int y)
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

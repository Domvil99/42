/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:06:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 18:06:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	set_defaults_bonus(t_app_bonus *app)
{
	app->view.min_re = -2.2;
	app->view.max_re = 1.8;
	app->view.min_im = -1.8;
	app->view.max_im = 1.8;
	app->max_iter = MAX_ITER;
	app->palette_shift = 0;
	app->mlx = NULL;
	app->win = NULL;
	app->img.ptr = NULL;
	app->img.addr = NULL;
}

static int	init_image_bonus(t_app_bonus *app)
{
	app->img.ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img.ptr)
		return (0);
	app->img.addr = mlx_get_data_addr(app->img.ptr, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	if (!app->img.addr)
		return (0);
	return (1);
}

int	init_app_bonus(t_app_bonus *app)
{
	set_defaults_bonus(app);
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "fractol_bonus");
	if (!app->win)
		destroy_and_exit_bonus(app, 1);
	if (!init_image_bonus(app))
		destroy_and_exit_bonus(app, 1);
	return (1);
}

void	destroy_and_exit_bonus(t_app_bonus *app, int code)
{
	if (app->img.ptr)
		mlx_destroy_image(app->mlx, app->img.ptr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	exit(code);
}

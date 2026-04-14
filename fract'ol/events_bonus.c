/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:09:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 18:09:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_view_bonus(t_app_bonus *app, double dx, double dy)
{
	double	range_re;
	double	range_im;

	range_re = app->view.max_re - app->view.min_re;
	range_im = app->view.max_im - app->view.min_im;
	app->view.min_re += range_re * dx;
	app->view.max_re += range_re * dx;
	app->view.min_im += range_im * dy;
	app->view.max_im += range_im * dy;
}

int	handle_key_bonus(int keycode, t_app_bonus *app)
{
	if (keycode == KEY_ESC)
		destroy_and_exit_bonus(app, 0);
	if (keycode == KEY_C)
		app->palette_shift += 12;
	if (keycode == KEY_V)
		app->palette_shift -= 12;
	if (keycode == KEY_LEFT)
		move_view_bonus(app, -0.08, 0.0);
	if (keycode == KEY_RIGHT)
		move_view_bonus(app, 0.08, 0.0);
	if (keycode == KEY_UP)
		move_view_bonus(app, 0.0, -0.08);
	if (keycode == KEY_DOWN)
		move_view_bonus(app, 0.0, 0.08);
	render_fractal_bonus(app);
	return (0);
}

int	handle_mouse_bonus(int button, int x, int y, t_app_bonus *app)
{
	if (button == 4)
		zoom_view_bonus(app, 0.80, x, y);
	else if (button == 5)
		zoom_view_bonus(app, 1.25, x, y);
	else
		return (0);
	if (app->max_iter < 320)
		app->max_iter += 1;
	render_fractal_bonus(app);
	return (0);
}

int	handle_close_bonus(t_app_bonus *app)
{
	destroy_and_exit_bonus(app, 0);
	return (0);
}

int	handle_expose_bonus(t_app_bonus *app)
{
	render_fractal_bonus(app);
	return (0);
}

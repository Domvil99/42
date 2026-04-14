/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:24:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 17:24:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		destroy_and_exit(app, 0);
	if (keycode == KEY_C)
	{
		app->palette_shift = (app->palette_shift + 20) % 255;
		render_fractal(app);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_app *app)
{
	if (button == 4)
		zoom_view(app, 0.80, x, y);
	else if (button == 5)
		zoom_view(app, 1.25, x, y);
	else
		return (0);
	if (app->max_iter < 260)
		app->max_iter += 1;
	render_fractal(app);
	return (0);
}

int	handle_close(t_app *app)
{
	destroy_and_exit(app, 0);
	return (0);
}

int	handle_expose(t_app *app)
{
	render_fractal(app);
	return (0);
}

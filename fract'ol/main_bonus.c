/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:05:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 18:05:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	setup_hooks_bonus(t_app_bonus *app)
{
	mlx_key_hook(app->win, handle_key_bonus, app);
	mlx_mouse_hook(app->win, handle_mouse_bonus, app);
	mlx_hook(app->win, EVT_DESTROY, 0, handle_close_bonus, app);
	mlx_hook(app->win, EVT_EXPOSE, 0, handle_expose_bonus, app);
}

int	main(int argc, char **argv)
{
	t_app_bonus	app;

	if (!parse_args_bonus(&app, argc, argv))
		return (1);
	if (!init_app_bonus(&app))
		return (1);
	render_fractal_bonus(&app);
	setup_hooks_bonus(&app);
	mlx_loop(app.mlx);
	return (0);
}

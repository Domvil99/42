/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:12:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 17:12:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	setup_hooks(t_app *app)
{
	mlx_key_hook(app->win, handle_key, app);
	mlx_mouse_hook(app->win, handle_mouse, app);
	mlx_hook(app->win, EVT_DESTROY, 0, handle_close, app);
	mlx_hook(app->win, EVT_EXPOSE, 0, handle_expose, app);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (!parse_args(&app, argc, argv))
		return (1);
	if (!init_app(&app))
		return (1);
	render_fractal(&app);
	setup_hooks(&app);
	mlx_loop(app.mlx);
	return (0);
}

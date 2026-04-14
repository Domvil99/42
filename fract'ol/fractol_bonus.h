/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:05:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 21:21:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 900
# define HEIGHT 700
# define MAX_ITER 90
# define KEY_ESC 65307
# define KEY_C 99
# define KEY_V 118
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define EVT_DESTROY 17
# define EVT_EXPOSE 12

typedef enum e_fractal_bonus
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA,
	FRACTAL_BURNING_SHIP
}	t_fractal_bonus;

typedef struct s_complex_bonus
{
	double	re;
	double	im;
}	t_complex_bonus;

typedef struct s_img_bonus
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_bonus;

typedef struct s_view_bonus
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_view_bonus;

typedef struct s_app_bonus
{
	void			*mlx;
	void			*win;
	t_img_bonus		img;
	t_view_bonus	view;
	t_fractal_bonus	fractal;
	t_complex_bonus	julia_c;
	int				max_iter;
	int				palette_shift;
}	t_app_bonus;

int		parse_args_bonus(t_app_bonus *app, int argc, char **argv);
int		init_app_bonus(t_app_bonus *app);
void	render_fractal_bonus(t_app_bonus *app);
void	destroy_and_exit_bonus(t_app_bonus *app, int code);
int		handle_key_bonus(int keycode, t_app_bonus *app);
int		handle_mouse_bonus(int button, int x, int y, t_app_bonus *app);
int		handle_close_bonus(t_app_bonus *app);
int		handle_expose_bonus(t_app_bonus *app);
int		mandelbrot_iter_bonus(t_complex_bonus c, int max_iter);
int		julia_iter_bonus(t_complex_bonus z, t_complex_bonus c, int max_iter);
int		burning_ship_iter_bonus(t_complex_bonus c, int max_iter);
int		color_from_iter_bonus(int iter, int max_iter, int shift);
void	zoom_view_bonus(t_app_bonus *app, double factor, int x, int y);
void	move_view_bonus(t_app_bonus *app, double dx, double dy);
double	ft_atod_bonus(const char *s, int *ok);
void	print_usage_bonus(void);

#endif

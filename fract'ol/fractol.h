/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:11:00 by saospina          #+#    #+#             */
/*   Updated: 2026/04/14 17:19:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 900
# define HEIGHT 700
# define MAX_ITER 1000
# define KEY_ESC 65307
# define KEY_C 99
# define EVT_DESTROY 17
# define EVT_EXPOSE 12

typedef enum e_fractal
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA
}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_view
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_view;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_view		view;
	t_fractal	fractal;
	t_complex	julia_c;
	int			max_iter;
	int			palette_shift;
}	t_app;

int		parse_args(t_app *app, int argc, char **argv);
int		init_app(t_app *app);
void	render_fractal(t_app *app);
void	destroy_and_exit(t_app *app, int code);
int		handle_key(int keycode, t_app *app);
int		handle_mouse(int button, int x, int y, t_app *app);
int		handle_close(t_app *app);
int		handle_expose(t_app *app);
int		mandelbrot_iter(t_complex c, int max_iter);
int		julia_iter(t_complex z, t_complex c, int max_iter);
int		color_from_iter(int iter, int max_iter, int shift);
void	zoom_view(t_app *app, double factor, int x, int y);
double	ft_atod(const char *s, int *ok);
void	print_usage(void);

#endif
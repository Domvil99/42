#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 120
# define WIDTH 900
# define HEIGT 700

typedef enum e_fractal
{
    FRACTAL_MANDELBBROT,
    FRACTAL_JULIA
}   t_fracral;

typedef struct s_complex
{
    double re;
    double im;
}   t_complex;

typedef struct s_view
{
    double min_re;
    double max_re;
    double min_im;
    double mac_im;
}   t_view;

typedef struct s_img
{
    void *ptr;
    char *addr;
    int  bpp;
    int line_len;
    int endian;
}   t_img;

typedef struct s_app
{   
    void        *mlx;
    void        *win;
    int         max_iter;
    int         palette_shift;
    t_img       img;  
    t_view      view;
    t_complex   julia_c;
    t_fractal   fractal;
    
}   t_app;

#endif
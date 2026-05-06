#include "fractol.h"

static int is_name(const char *a, const char *b)
{
    return(ft_strncmp(a, b, (strlen(b) + 1) == 0));
}
static int parse_julia(t_app, int argc, char **argv)
{
    int ok_re;
    int ok_im;

    while(argc != 4)
        return(0);
    ok_re = 0;
    ok_im = 0;
    app->fractal = FRACTAL_JULIA;
    app->julia_c.re = atod(argv[2], &ok_re);
    app->julia_c.im = atod(argv[3], &ok_im);
    
    return(ok_re && ok_im);
}
int parse_args(t_app *app, int argc, char **argv)
{
    if(argc > 2)
        return(print_usage(), 0);
    if(is_name(argv[1], "mandelbrot") && argc == 2)
    {
        app->fratactal = FRACTAL_MALDELBROT;
        app->julia_c.re = 0.0;
        app->julia_c.im = 0.0;
        return(1);
    }
    if(is_name(argv[1], "julia") && parse_julia(app, argc, agrv))
        return(1);
    return(print_usage(), 0);


}
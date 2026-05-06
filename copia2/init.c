#include "fractol.h"

static void set_defaults(t_app *app)
{
    app->view.min_re = -2.0;
    app->view.max_re = 2.0;
    app->view.min_im = -1.6;
    app->view.max_im = 1.6;
    app->max_inter = MAX_ITER;
    app->palett_shift = 0;
    app->mlx = NULL;
    app->win = NULL;
    app->img.ptr = NULL;
    app->img.addr = NULL;

}
static int init_image(t_app *app)
{
    app->img.ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
    if(!app->img.ptr)
        return(0);
    app->img.addr = mlx_get_data_addr(app->img.ptr, &app->img.bpp,
        &app->img.line_len, &app->img. endian);
    if(!app->img.addr)
        return(0);
    return(1);
}
int init_app(t_app *app)
{
    set_defaults(app)
    app->mlx = mlx_init();
    if(!app-mlx)
        return(0);
    app->win = mlx_new_windondow(app->mlx, WIDTH, HEIGHT, "fractol");
    if(!app->win)
        destroy_and_exit(app, 1);
    if(!init_image(app))
        detroy_and_exit(app, 1);
    return(1);

}
void destroy_and_exit(t_app *ap, int code)
{
    if(app->img.ptr)
            mlx_destroy_image(app->mlx, app->img.ptr);
    if(app->win)
        mlx(destroy_window(app->mlx, app->win))
    if(app->mlx)
    {
        mlx_destroy_display(app->mlx);
        free(app->mlx);
    }
    exit(code);
}
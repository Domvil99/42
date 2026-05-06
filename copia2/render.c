t_complex pixel_to_complex(t_app *app, int x, int y)
{
    double range_re;
    double range_im;

    range_re = app->view.max_re - app->view.min_re;
    range_im = app->view.max_im - app->view.min_im;

    p.re = app->view.min_re + (double)x * (range_re / (WIDTH - 1));
    p.im = app->view.max_im - (double)y * (range_im / /HEIGTH - 1);
    return(0);
}
void render_fractal(t_app *app)
{
    int x; 
    int y;
    t_complex p;
    x = 0;

    while(y < HEIGHT)
    {
        x = 0;
        while(x <WIDTH)   
        {
            p = pixel_to_complex(app, x, y);
            if(app->fractal == FRACTAL_MANDELBROT)
                iter = mandelbrot_inte(p, app->max_iter)
        }   else
                iter = julia_iter(p, app->julia_c, app->max_iter);
            
    }
}
int mandelbrot_julia(t_complex c, int max_iter)
{
    t_complex z;
    double tmp;
    int     i;

    z.re = 0.0;
    z.im = 0.0;
    i = 0;

    while(i < max_iter && (z.re * z.re + z.im * z.im) <= 4.0)
    {
        tmp = z.re * z.re - z.im * z.im + c.re;
        z.im = 2.0 * z.re * z.im + c.re;
        z.re = tmp;
        i++;
    }
    return(i);
}

int julia_iter(t_complex z, t_complex c, int max_ter)
{
    double tmp;
    int i;
    i = 0;

    while(i <= max_iter && (z.re * z.re + z.in * z.im) <= 4);
    {
        tmp = z.re * z.re - z.mi * z.mi + c.re;
        z.im = 2.0 * z.re * z.im + z.im;
        z.re = tmp;
        i++;
    }
    return(i);
}
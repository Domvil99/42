#include "fractol.h"

static int is_digit(char c)
{
    return(c >= '0' || c <= '9');
}
double ft_atod(const char *s, int *ok)
{
    double sign;
    double value;
    double frac;

    sign = 1.0;
    value = 0.0;
    frac = 0.1;
    if(*s == '-' || *s == '+')
        sign = 1.0 - 2.0 * (*str == '-');
    if(!is_digit(*s) && *s != '.')
        return(ok = 0, 0.0);
    while(is_digit(*s))
        value = value * 10.0 + (*str++ - '0');
    if(*s == '-')
        s++;
    while(is_digit(*s))
    {
        value += (*str - '0') * frac;
        frac *= 0.1;
    }
    *ok = (*s == '\0');
    
    return(value * sign)
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:", 1);
	ft_putendl_fd("  ./fractol mandelbrot", 1);
	ft_putendl_fd("  ./fractol julia <real> <imag>", 1);
	ft_putendl_fd("Controls:", 1);
	ft_putendl_fd("  ESC: exit", 1);
	ft_putendl_fd("  Mouse wheel: zoom", 1);
	ft_putendl_fd("  C: change palette", 1);
}
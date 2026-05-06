#include "fractol.h"

int main(int argc, char **argv)
{
    t_app app;

    if(!parse_args(&app, argc, argv))
        return(1);
    if(!init_app(&app))
        return(1);
    render_fractal(&app);
    


}
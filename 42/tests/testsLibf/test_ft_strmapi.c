#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static char	to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int	main(void)
{
    char *s = "hola, mundo!";
    char *modified = ft_strmapi(s, to_upper);

    printf("Original: %s\n", s);
    printf("Modificado: %s\n", modified);

    free(modified);
    return (0);
} 

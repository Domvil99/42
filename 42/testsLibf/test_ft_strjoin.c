#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char	*s1;
    char	*s2;
    char	*joined;

    s1 = "Hola, ";
    s2 = "mundo!";
    joined = ft_strjoin(s1, s2);

    if (!joined)
        return (1);
    else
        printf("Cadena unida: %s\n", joined);
    free(joined);
    return (0);
}

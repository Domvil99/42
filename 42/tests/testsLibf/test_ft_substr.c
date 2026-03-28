#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char	*original;
    char	*sub1;
    char	*sub2;

    original = "Hola, mundo!";
    sub1 = ft_substr(original, 5, 5);
    sub2 = ft_substr(original, 20, 5);
    printf("Subcadena (5,5): %s\n", sub1);
    printf("Subcadena (fuera de limites): %s\n", sub2);
    free(sub1);
    free(sub2);
    return (0);
}

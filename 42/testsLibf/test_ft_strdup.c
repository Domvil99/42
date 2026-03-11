#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char	*original;
    char	*copy;

    original = "Hola, mundo!";
    copy = ft_strdup(original);
    if (!copy)
        return (1);
    else
        printf("Copia creada: %s\n", copy);

    free(copy);
    return (0);
}

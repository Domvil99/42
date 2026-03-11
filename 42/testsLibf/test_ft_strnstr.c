#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	haystack[] = "Hola, mundo!";
	char	needle[] = "mundo";
	char	*result;

	result = ft_strnstr(haystack, needle, 12);

    if (result)
        printf("Encontrado 'mundo' en: %s\n", result);
    else
        printf("'mundo' no encontrado.\n");

    return (0);
}

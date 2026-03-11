#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str1[] = "Hola";
    char str2[] = "Hola";
    int result;

    result = ft_memcmp(str1, str2, 4);
    printf("Resultado de la comparación: %d\n", result);

    return 0;
}

#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[] = "Hola Mundo";
    char *result;

    result = ft_memchr(str, 'M', 10);
    if (result != NULL)
        printf("Encontrado: %s\n", result);
    else
        printf("No encontrado\n");

    return 0;
} 

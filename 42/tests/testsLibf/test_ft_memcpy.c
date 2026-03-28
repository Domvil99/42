#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char src[] = "Hola Mundo";
    char dst[20];

    ft_memcpy(dst, src, 10);
    printf("Cadena copiada: %s\n", dst);

    return 0;
}

#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char str[] = "Hola, mundo!";
    ft_memmove(str + 6, str, 5);  // Mueve "Hola," sobre sí mismo
    printf("Después de memmove: %s\n", str);
    return (0);
}

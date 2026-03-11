#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char str[] = "Hola Mundo!";
    printf("Antes memset: %s\n", str);
    ft_memset(str, '*', 5);
    printf("Después memset: %s\n", str);
    return (0);
}

#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    printf("ft_isprint(32) = %d\n", ft_isprint(32));  // Espacio ' '
    printf("ft_isprint(126) = %d\n", ft_isprint(126)); // '~'
    printf("ft_isprint(8) = %d\n", ft_isprint(8));   // No imprimible (backspace)
    return (0);
}

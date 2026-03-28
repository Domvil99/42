#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    printf("ft_isascii(65) = %d\n", ft_isascii(65));   // 'A'
    printf("ft_isascii(200) = %d\n", ft_isascii(200)); // Fuera de ASCII estándar
    return (0);
}

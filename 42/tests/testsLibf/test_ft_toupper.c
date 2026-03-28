#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    printf("ft_toupper('a') = %c\n", ft_toupper('a'));
    printf("ft_toupper('z') = %c\n", ft_toupper('z'));
    printf("ft_toupper('A') = %c\n", ft_toupper('A'));
    printf("ft_toupper('1') = %c\n", ft_toupper('1'));
    return (0);
}

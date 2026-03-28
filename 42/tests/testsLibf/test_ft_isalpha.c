#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
    printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
    printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
    return (0);
}

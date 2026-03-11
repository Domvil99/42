#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
    printf("ft_isalnum('5') = %d\n", ft_isalnum('5'));
    printf("ft_isalnum('!') = %d\n", ft_isalnum('!'));
    return (0);
}

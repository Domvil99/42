#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isascii(65) = %d\n", ft_isascii(65));   // 'A'
    printf("ft_isascii(200) = %d\n", ft_isascii(200)); // Fuera de ASCII estándar
    return (0);
}
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
    printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
    printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
    return (0);
}
*/
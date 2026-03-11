#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
    printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
    printf("ft_isdigit('A') = %d\n", ft_isdigit('A'));
    return (0);
}
*/
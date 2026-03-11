#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	printf("atoi('42') = %d\n", ft_atoi("42"));
	printf("atoi('-42') = %d\n", ft_atoi("-42"));
	printf("atoi('  123') = %d\n", ft_atoi("  123"));
	printf("atoi('abc42') = %d\n", ft_atoi("abc42"));
	return (0);
}

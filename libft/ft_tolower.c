#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int main(void)
{
    char upper = 'A';
    char lower = 'a';

    printf("ft_tolower('%c') = '%c'\n", upper, ft_tolower(upper));
    printf("ft_tolower('%c') = '%c'\n", lower, ft_tolower(lower));
    return 0;
}
*/
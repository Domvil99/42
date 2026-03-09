#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
    char str[] = "Hola Mundo!";
    printf("Antes memset: %s\n", str);
    ft_memset(str, '*', 5);
    printf("Después memset: %s\n", str);
    return (0);
}
*/
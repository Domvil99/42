#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "Hola Mundo";
    char *result;

    result = ft_memchr(str, 'M', 10);
    if (result != NULL)
        printf("Encontrado: %s\n", result);
    else
        printf("No encontrado\n");

    return 0;
} 
*/

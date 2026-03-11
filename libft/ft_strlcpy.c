#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	src[] = "Hola, mundo!";
	char	dst[6];
	size_t	len;

	len = ft_strlcpy(dst, src, sizeof(dst));

    printf("Después de strlcpy: %s\n", dst);
    printf("Longitud de src: %zu\n", len);

    return (0);
}
*/

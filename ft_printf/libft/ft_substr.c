#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*original;
    char	*sub1;
    char	*sub2;

    original = "Hola, mundo!";
    sub1 = ft_substr(original, 5, 5);
    sub2 = ft_substr(original, 20, 5);
    printf("Subcadena (5,5): %s\n", sub1);
    printf("Subcadena (fuera de limites): %s\n", sub2);
    free(sub1);
    free(sub2);
    return (0);
}
*/
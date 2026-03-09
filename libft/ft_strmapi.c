#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include "libft.h"
#include <stdio.h>

char	to_upper(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int	main(void)
{
    char *s = "hola, mundo!";
    char *modified = ft_strmapi(s, to_upper);

    printf("Original: %s\n", s);
    printf("Modificado: %s\n", modified);

    free(modified);
    return (0);
} 
*/
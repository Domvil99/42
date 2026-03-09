#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/*
int main(void)
{
char str[] = "Hola Mundo";
int len = ft_strlen(str);                           
 	printf("La longitud de la cadena es: %d\n", len);
 	return (0);
 }
*/
#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int main(void)
{
	char	str[] = "hola, mundo!";

	ft_striteri(str, to_upper);
	printf("String modificada: %s\n", str);
	return (0);
}

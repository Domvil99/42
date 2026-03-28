#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	str[] = "Hola, mundo!";
	char	*result;

	result = ft_strrchr(str, 'o');
	if (result)
		printf("Ultima aparicion de 'o': %s\n", result);
	else
		printf("'o' no encontrado.\n");
	return (0);
}

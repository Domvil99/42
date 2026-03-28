#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	const char	*str1;
	const char	*str2;
	int		result;

	str1 = "dfghjkl";
	str2 = "Hola Mundo";
	result = ft_strncmp(str1, str2, 4);
	printf("Resultado de la comparacion: %d\n", result);
	return (0);
}

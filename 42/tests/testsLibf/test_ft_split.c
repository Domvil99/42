#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void	free_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(void)
{
	char	**result;
	char	str[] = "Hola, mundo! Bienvenido a la programacion.";
	size_t	i;

	result = ft_split(str, ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("Palabra %zu: %s\n", i, result[i]);
		i++;
	}
	free_split(result);
	return (0);
}

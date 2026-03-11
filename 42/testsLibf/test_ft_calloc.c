#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	int	*arr;
	int	i;

	arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf("Error en calloc\n");
		return (1);
	}
	printf("Caso normal:\n");
	i = 0;
	while (i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	arr = (int *)ft_calloc(0, sizeof(int));
	if (!arr)
		printf("Error en calloc (count = 0)\n");
	else
		printf("Caso count = 0: Puntero válido obtenido\n");
	free(arr);
	arr = (int *)ft_calloc(5, 0);
	if (!arr)
		printf("Error en calloc (size = 0)\n");
	else
		printf("Caso size = 0: Puntero válido obtenido\n");
	free(arr);
	arr = (int *)ft_calloc((size_t)-1, (size_t)-1);
	if (!arr)
		printf("Error esperado en calloc (overflow)\n");
	return (0);
}

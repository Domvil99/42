/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:29:58 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:29:36 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > ((size_t)-1) / size)
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/*
#include <stdio.h>

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
*/

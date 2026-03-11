/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}
/*
#include <stdio.h>

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
*/
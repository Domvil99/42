/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:31:27 by saospina           #+#    #+#            */
/*   Updated: 2025/05/18 17:53:52 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;
	char	*trimmed;

	s1 = "###Hola, mundo###";
	set = "#";
	trimmed = ft_strtrim(s1, set);
	printf("Original: \"%s\"\n", s1);
	printf("Recortado: \"%s\"\n", trimmed);
	free(trimmed);
	return (0);
}
*/

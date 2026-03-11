/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(len);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(joined + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (joined);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*s1;
    char	*s2;
    char	*joined;

    s1 = "Hola, ";
    s2 = "mundo!";
    joined = ft_strjoin(s1, s2);

    if (!joined)
        return (1);
    else
        printf("Cadena unida: %s\n", joined);
    free(joined);
    return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:31:06 by saospina           #+#    #+#            */
/*   Updated: 2025/05/18 17:31:07 by saospina          ###   ########.fr      */
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

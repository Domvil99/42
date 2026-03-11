/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:30:15 by saospina           #+#    #+#            */
/*   Updated: 2025/05/18 17:30:18 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc(len);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, len);
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*original;
    char	*copy;

    original = "Hola, mundo!";
    copy = ft_strdup(original);
    if (!copy)
        return (1);
    else
        printf("Copia creada: %s\n", copy);

    free(copy);
    return (0);
}

*/

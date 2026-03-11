/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:31:57 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:46:59 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long		nb;

	nb = n;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		str[len] = '0' + (nb % 10);
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*s1;
    char	*s2;
    char	*s3;

    s1 = ft_itoa(42);
    s2 = ft_itoa(-12345);
    s3 = ft_itoa(0);
    printf("itoa(42) = %s\n", s1);
    printf("itoa(-12345) = %s\n", s2);
    printf("itoa(0) = %s\n", s3);
    free(s1);
    free(s2);
    free(s3);

    return (0);
}
*/

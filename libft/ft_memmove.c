/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/05/18 17:21:57 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 19:10:23 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_forward(unsigned char *d,
	const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	ft_memmove_backward(unsigned char *d,
	const unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
		ft_memmove_backward(d, s, n);
	else
		ft_memmove_forward(d, s, n);
	return (dst);
}
/*
int	main(void)
{
    char str[] = "Hola, mundo!";
    ft_memmove(str + 6, str, 5);  // Mueve "Hola," sobre sí mismo
    printf("Después de memmove: %s\n", str);
    return (0);
}
*/

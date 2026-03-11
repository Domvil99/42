/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/05/18 17:17:30 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:36:56 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
    printf("ft_isdigit('A') = %d\n", ft_isdigit('A'));
    return (0);
}
*/

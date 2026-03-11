/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/05/18 17:18:29 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:33:58 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
    printf("ft_isalnum('5') = %d\n", ft_isalnum('5'));
    printf("ft_isalnum('!') = %d\n", ft_isalnum('!'));
    return (0);
}
*/

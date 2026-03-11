/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:16:34 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:34:56 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
    printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
    printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
    return (0);
}
*/

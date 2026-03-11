/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:18:47 by saospina           #+#    #+#            */
/*   Updated: 2025/06/26 18:36:37 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
    printf("ft_isascii(65) = %d\n", ft_isascii(65));   // 'A'
    printf("ft_isascii(200) = %d\n", ft_isascii(200)); // Fuera de ASCII estándar
    return (0);
}
*/

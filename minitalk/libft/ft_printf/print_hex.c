/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:55:19 by saospina           #+#    #+#            */
/*   Updated: 2025/10/21 15:55:19 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, const char format)
{
	if (format == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
}

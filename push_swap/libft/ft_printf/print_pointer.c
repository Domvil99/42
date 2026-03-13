/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:56:06 by saospina           #+#    #+#            */
/*   Updated: 2025/10/21 15:56:06 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_putnbr_base(ptr, "0123456789abcdef");
	return (len);
}

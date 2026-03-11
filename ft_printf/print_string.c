/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:56:04 by saospina          #+#    #+#             */
/*   Updated: 2025/10/21 15:56:04 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:56:28 by saospina           #+#    #+#            */
/*   Updated: 2025/10/21 15:56:28 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

int	ft_printf(const char *format, ...);

int	print_char(int c);
int	print_string(char *s);
int	print_pointer(unsigned long long ptr);
int	print_decimal(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, const char format);
int	print_percent(void);
int	ft_putnbr_base(unsigned long long nbr, char *base);

#endif

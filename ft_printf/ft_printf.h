/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		left_align;
	int		zero_pad;
	int		width;
	int		precision;
	int		has_precision;
	int		plus;
	int		space;
	int		hash;
	int		type;
}	t_format;

typedef struct s_int_data
{
	char	*raw;
	char	*num;
	int		num_len;
	int		sign_char;
	int		sign_len;
	int		zero_pad;
	int		full_len;
	int		space_pad;
}	t_int_data;

int	ft_printf(const char *format, ...);

# ifndef FT_PRINTF_BONUS

int	print_char(int c);
int	print_string(char *s);
int	print_pointer(unsigned long long ptr);
int	print_decimal(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, const char format);
int	print_percent(void);
int	ft_putnbr_base(unsigned long long nbr, char *base);

# else

int	handle_format(const char *format, va_list args, int *i);
int	parse_format(const char *format, t_format *f);
int	print_char(va_list args, t_format f);
int	print_str(va_list args, t_format f);
int	print_int(va_list args, t_format f);
int	print_unsigned(va_list args, t_format f);
int	print_hex(va_list args, t_format f);
int	print_pointer(va_list args, t_format f);

# endif

#endif

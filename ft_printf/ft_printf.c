#include "ft_printf.h"

static int	pf_dispatch(char format, va_list args)
{
	if (format == 'c')
		return (pf_print_char(va_arg(args, int)));
	if (format == 's')
		return (pf_print_string(va_arg(args, char *)));
	if (format == 'p')
		return (pf_print_pointer(va_arg(args, unsigned long long)));
	if (format == 'd' || format == 'i')
		return (pf_print_decimal(va_arg(args, int)));
	if (format == 'u')
		return (pf_print_unsigned(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (pf_print_hex(va_arg(args, unsigned int), format));
	if (format == '%')
		return (pf_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += pf_dispatch(format[++i], args);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

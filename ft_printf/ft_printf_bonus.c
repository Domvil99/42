#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed += handle_format(&format[i], args, &i);
		}
		else
			printed += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

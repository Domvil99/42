#include "ft_printf.h"

int	pf_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (pf_putnbr_base(n, "0123456789abcdef"));
	return (pf_putnbr_base(n, "0123456789ABCDEF"));
}

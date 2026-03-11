#include "ft_printf.h"

int	pf_print_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += pf_putnbr_base(ptr, "0123456789abcdef");
	return (len);
}

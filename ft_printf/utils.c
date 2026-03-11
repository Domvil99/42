#include "ft_printf.h"

int	pf_putnbr_base(unsigned long long nbr, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
		len += pf_putnbr_base(nbr / base_len, base);
	len += write(1, &base[nbr % base_len], 1);
	return (len);
}

int	pf_print_percent(void)
{
	return (write(1, "%", 1));
}

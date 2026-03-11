#include "ft_printf.h"

static int	pf_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count = 1;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	pf_print_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (pf_count_digits(n));
}

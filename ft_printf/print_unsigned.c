#include "ft_printf.h"

static void	pf_put_unsigned(unsigned int n)
{
	if (n >= 10)
		pf_put_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

static int	pf_count_udigits(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	pf_print_unsigned(unsigned int n)
{
	pf_put_unsigned(n);
	return (pf_count_udigits(n));
}

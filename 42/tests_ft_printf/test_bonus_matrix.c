#include "../C/ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	total;

	total = 0;
	total += ft_printf("B01|%#x|\n", 0x2a);
	total += ft_printf("B02|%#X|\n", 0x2a);
	total += ft_printf("B03|%#08x|\n", 0x2a);
	total += ft_printf("B04|%+d|\n", 42);
	total += ft_printf("B05|% d|\n", 42);
	total += ft_printf("B06|%+8d|\n", 42);
	total += ft_printf("B07|%-8d|\n", 42);
	total += ft_printf("B08|%08d|\n", 42);
	total += ft_printf("B09|%.5d|\n", 42);
	total += ft_printf("B10|%8.5d|\n", 42);
	total += ft_printf("B11|%-8.5d|\n", 42);
	total += ft_printf("B12|%#.0x|\n", 0);
	total += ft_printf("B13|%+.0d|\n", 0);
	fprintf(stderr, "RET_TOTAL=%d\n", total);
	return (0);
}

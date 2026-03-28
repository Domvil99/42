#include "../../C/ft_printf/ft_printf.h"
#include <stdint.h>
#include <stdio.h>

int	main(void)
{
	int	total;

	total = 0;
	total += ft_printf("T01|%c|\n", 'A');
	total += ft_printf("T02|%c|\n", 'Z');
	total += ft_printf("T03|%c|\n", 'Q');
	total += ft_printf("T04|%s|\n", "hola");
	total += ft_printf("T05|%s|\n", "abcdef");
	total += ft_printf("T06|%s|\n", "xy");
	total += ft_printf("T07|%s|\n", "xy");
	total += ft_printf("T08|%s|\n", (char *)0);
	total += ft_printf("T09|%p|\n", (void *)0);
	total += ft_printf("T10|%p|\n", (void *)(uintptr_t)0x1234);
	total += ft_printf("T11|%d|\n", 42);
	total += ft_printf("T12|%i|\n", -42);
	total += ft_printf("T13|%d|\n", 123);
	total += ft_printf("T14|%d|\n", 123);
	total += ft_printf("T15|%d|\n", 123);
	total += ft_printf("T16|%d|\n", 123);
	total += ft_printf("T17|%d|\n", 0);
	total += ft_printf("T18|%u|\n", 4294967295U);
	total += ft_printf("T19|%u|\n", 0U);
	total += ft_printf("T20|%x|\n", 0x12ab);
	total += ft_printf("T21|%X|\n", 0x12ab);
	total += ft_printf("T22|%x|\n", 0x2f);
	total += ft_printf("T23|%%|\n");
	fprintf(stderr, "RET_TOTAL=%d\n", total);
	return (0);
}

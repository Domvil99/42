#include <stdint.h>
#include <stdio.h>

static char	*get_null_string(void)
{
	return ((char *)0);
}

int	main(void)
{
	int	total;

	total = 0;
	total += printf("T01|%c|\n", 'A');
	total += printf("T02|%c|\n", 'Z');
	total += printf("T03|%c|\n", 'Q');
	total += printf("T04|%s|\n", "hola");
	total += printf("T05|%s|\n", "abcdef");
	total += printf("T06|%s|\n", "xy");
	total += printf("T07|%s|\n", "xy");
	total += printf("T08|%s|\n", get_null_string());
	total += printf("T09|%p|\n", (void *)0);
	total += printf("T10|%p|\n", (void *)(uintptr_t)0x1234);
	total += printf("T11|%d|\n", 42);
	total += printf("T12|%i|\n", -42);
	total += printf("T13|%d|\n", 123);
	total += printf("T14|%d|\n", 123);
	total += printf("T15|%d|\n", 123);
	total += printf("T16|%d|\n", 123);
	total += printf("T17|%d|\n", 0);
	total += printf("T18|%u|\n", 4294967295U);
	total += printf("T19|%u|\n", 0U);
	total += printf("T20|%x|\n", 0x12ab);
	total += printf("T21|%X|\n", 0x12ab);
	total += printf("T22|%x|\n", 0x2f);
	total += printf("T23|%%|\n");
	fprintf(stderr, "RET_TOTAL=%d\n", total);
	return (0);
}

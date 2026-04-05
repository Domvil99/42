#include <stdio.h>

int	main(void)
{
	int	total;

	total = 0;
	total += printf("B01|%#x|\n", 0x2a);
	total += printf("B02|%#X|\n", 0x2a);
	total += printf("B03|%#08x|\n", 0x2a);
	total += printf("B04|%+d|\n", 42);
	total += printf("B05|% d|\n", 42);
	total += printf("B06|%+8d|\n", 42);
	total += printf("B07|%-8d|\n", 42);
	total += printf("B08|%08d|\n", 42);
	total += printf("B09|%.5d|\n", 42);
	total += printf("B10|%8.5d|\n", 42);
	total += printf("B11|%-8.5d|\n", 42);
	total += printf("B12|%#.0x|\n", 0);
	total += printf("B13|%+.0d|\n", 0);
	fprintf(stderr, "RET_TOTAL=%d\n", total);
	return (0);
}

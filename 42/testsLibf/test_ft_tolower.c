#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char upper = 'A';
    char lower = 'a';

    printf("ft_tolower('%c') = '%c'\n", upper, ft_tolower(upper));
    printf("ft_tolower('%c') = '%c'\n", lower, ft_tolower(lower));
    return 0;
}

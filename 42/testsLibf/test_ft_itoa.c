#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
    char	*s1;
    char	*s2;
    char	*s3;

    s1 = ft_itoa(42);
    s2 = ft_itoa(-12345);
    s3 = ft_itoa(0);
    printf("itoa(42) = %s\n", s1);
    printf("itoa(-12345) = %s\n", s2);
    printf("itoa(0) = %s\n", s3);
    free(s1);
    free(s2);
    free(s3);

    return (0);
}

#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	src[] = "Hola, mundo!";
	char	dst[6];
	size_t	len;

	len = ft_strlcpy(dst, src, sizeof(dst));

    printf("Después de strlcpy: %s\n", dst);
    printf("Longitud de src: %zu\n", len);

    return (0);
}

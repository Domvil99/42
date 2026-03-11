#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	dst[20] = "Hola";
	char	src[] = ", mundo!";
	size_t	len;

	len = ft_strlcat(dst, src, sizeof(dst));

    printf("Después de strlcat: %s\n", dst);
    printf("Longitud combinada: %zu\n", len);

    return (0);
}

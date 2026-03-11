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
	char	*set;
	char	*trimmed;

	s1 = "###Hola, mundo###";
	set = "#";
	trimmed = ft_strtrim(s1, set);
	printf("Original: \"%s\"\n", s1);
	printf("Recortado: \"%s\"\n", trimmed);
	free(trimmed);
	return (0);
}

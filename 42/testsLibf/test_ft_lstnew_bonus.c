#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	t_list	*n;
	char	*txt;

	txt = "hola";
	n = ft_lstnew(txt);
	if (!n)
		return (1);
	printf("%s\n", (char *)n->content);
	free(n);
	return (0);
}

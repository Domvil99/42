#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void	del_str(void *p)
{
	free(p);
}

int	main(void)
{
	t_list	*n;
	char	*txt;

	txt = ft_strdup("hola");
	n = ft_lstnew(txt);
	ft_lstdelone(n, del_str);
	printf("ok\n");
	return (0);
}

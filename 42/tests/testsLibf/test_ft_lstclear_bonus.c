#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
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
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(ft_strdup("A"));
	b = ft_lstnew(ft_strdup("B"));
	a->next = b;
	ft_lstclear(&a, del_str);
	printf("%p\n", (void *)a);
	return (0);
}

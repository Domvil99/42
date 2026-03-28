#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void	print_str(void *p)
{
	printf("%s\n", (char *)p);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	a->next = b;
	ft_lstiter(a, print_str);
	free(b);
	free(a);
	return (0);
}

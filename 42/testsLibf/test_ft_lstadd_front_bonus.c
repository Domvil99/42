#include "../C/libft/libft.h"
#include "../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	ft_lstadd_front(&a, b);
	printf("%s\n", (char *)a->content);
	free(b);
	free(a);
	return (0);
}

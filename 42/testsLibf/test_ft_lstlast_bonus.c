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
	t_list	*last;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	a->next = b;
	last = ft_lstlast(a);
	printf("%s\n", (char *)last->content);
	free(b);
	free(a);
	return (0);
}

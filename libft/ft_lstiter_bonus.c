#include "libft_bonus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

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
*/

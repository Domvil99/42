#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	a->next = b;
	printf("%d\n", ft_lstsize(a));
	free(b);
	free(a);
	return (0);
}
*/

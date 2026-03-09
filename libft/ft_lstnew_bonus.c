#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

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
*/

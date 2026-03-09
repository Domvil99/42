#include "libft_bonus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

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
*/
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

static void	*dup_content(void *p)
{
	return (ft_strdup((char *)p));
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*copy;

	a = ft_lstnew(ft_strdup("A"));
	b = ft_lstnew(ft_strdup("B"));
	a->next = b;
	copy = ft_lstmap(a, dup_content, del_str);
	printf("%s %s\n", (char *)copy->content, (char *)copy->next->content);
	ft_lstclear(&a, del_str);
	ft_lstclear(&copy, del_str);
	return (0);
}

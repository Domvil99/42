/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static void	ft_clear_newlist(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_lstclear(lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_clear_newlist(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

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
*/

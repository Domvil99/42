/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domvil99 <domvil99@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:01:56 by domvil99          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:56 by domvil99         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
/*
#include <stdio.h>

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
*/

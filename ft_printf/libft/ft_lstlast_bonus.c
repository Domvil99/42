/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::      */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

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
*/

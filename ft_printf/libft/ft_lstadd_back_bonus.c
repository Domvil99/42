/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 07:48:38 by saospina           #+#    #+#            */
/*   Updated: 2026/03/11 15:53:48 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	ft_lstadd_back(&a, b);
	printf("%s\n", (char *)ft_lstlast(a)->content);
	free(b);
	free(a);
	return (0);
}
*/

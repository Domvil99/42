/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:02:38 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 17:24:58 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	node->next = *dst;
	*dst = node;
}

void	op_pa(t_node **a, t_node **b, int print)
{
	push_node(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	op_pb(t_node **a, t_node **b, int print)
{
	push_node(b, a);
	if (print)
		write(1, "pb\n", 3);
}

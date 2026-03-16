/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 09:24:12 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 21:50:36 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_rra(t_node **a, int print)
{
	rev_rotate_stack(a);
	if (print)
		write(1, "rra\n", 4);
}

void	op_rrb(t_node **b, int print)
{
	rev_rotate_stack(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_node **a, t_node **b, int print)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	if (print)
		write(1, "rrr\n", 4);
}

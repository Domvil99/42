/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:46:46 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 19:16:14 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	op_ra(t_node **a, int print)
{
	rotate_stack(a);
	if (print)
		write(1, "ra\n", 3);
}

void	op_rb(t_node **b, int print)
{
	rotate_stack(b);
	if (print)
		write(1, "rb\n", 3);
}

void	op_rr(t_node **a, t_node **b, int print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (print)
		write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:08:20 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 17:42:52 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	op_sa(t_node **a, int print)
{
	swap_top(a);
	if (print)
		write(1, "sa\n", 3);
}

void	op_sb(t_node **b, int print)
{
	swap_top(b);
	if (print)
		write(1, "sb\n", 3);
}

void	op_ss(t_node **a, t_node **b, int print)
{
	swap_top(a);
	swap_top(b);
	if (print)
		write(1, "ss\n", 3);
}

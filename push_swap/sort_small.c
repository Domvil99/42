/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:09:27 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 18:05:21 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		op_sa(a, 1);
	else if (f > s && s > t)
	{
		op_sa(a, 1);
		op_rra(a, 1);
	}
	else if (f > s && s < t && f > t)
		op_ra(a, 1);
	else if (f < s && s > t && f < t)
	{
		op_sa(a, 1);
		op_ra(a, 1);
	}
	else if (f < s && s > t && f > t)
		op_rra(a, 1);
}

static int	pos_of_min_index(t_node *a)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

static void	push_min_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = pos_of_min_index(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			op_ra(a, 1);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			op_rra(a, 1);
	}
	op_pb(a, b, 1);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		op_pa(a, b, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 20:05:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk_size(int size)
{
	if (size <= 100)
		return (14);
	if (size <= 500)
		return (30);
	return (60);
}

static int	find_max_index(t_node *b)
{
	int	max;

	max = INT_MIN;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static int	find_pos_of_index(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

static void	push_back_sorted(t_node **a, t_node **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max_index(*b);
		pos = find_pos_of_index(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
			while (pos--)
				op_rb(b, 1);
		else
		{
			pos = size - pos;
			while (pos--)
				op_rrb(b, 1);
		}
		op_pa(a, b, 1);
	}
}

void	sort_chunk(t_node **a, t_node **b)
{
	int	chunk;
	int	current;

	chunk = choose_chunk_size(stack_size(*a));
	current = 0;
	while (*a)
	{
		if ((*a)->index <= current)
		{
			op_pb(a, b, 1);
			op_rb(b, 1);
			current++;
		}
		else if ((*a)->index <= current + chunk)
		{
			op_pb(a, b, 1);
			current++;
		}
		else
			op_ra(a, 1);
	}
	push_back_sorted(a, b);
}

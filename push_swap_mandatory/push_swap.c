/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 10:10:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_dispatch(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted_stack(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			op_sa(a, 1);
		return ;
	}
	if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 500)
		sort_chunk(a, b);
	else
		sort_radix(a, b);
}

static int	setup_stacks(int argc, char **argv, t_node **a, int **arr)
{
	int	count;

	count = parse_numbers(argc, argv, arr);
	if (count < 0)
	{
		print_error();
		return (-1);
	}
	if (count <= 1)
	{
		free(*arr);
		return (0);
	}
	*a = build_stack(*arr, count);
	if (!*a || !assign_indices(*a, *arr, count))
	{
		free(*arr);
		free_stack(a);
		print_error();
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		ready;

	a = NULL;
	b = NULL;
	arr = NULL;
	ready = setup_stacks(argc, argv, &a, &arr);
	if (ready <= 0)
		return (ready < 0);
	sort_dispatch(&a, &b);
	free(arr);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

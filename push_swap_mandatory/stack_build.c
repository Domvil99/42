/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 10:10:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_pos(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

t_node	*build_stack(int *arr, int count)
{
	t_node	*a;
	t_node	*n;
	int		i;

	a = NULL;
	i = 0;
	while (i < count)
	{
		n = new_node(arr[i]);
		if (!n)
			return (free_stack(&a), NULL);
		add_back_node(&a, n);
		i++;
	}
	return (a);
}

int	assign_indices(t_node *a, int *arr, int count)
{
	int		*sorted;
	t_node	*tmp;

	sorted = malloc(sizeof(int) * count);
	if (!sorted)
		return (0);
	ft_memcpy(sorted, arr, sizeof(int) * count);
	sort_array(sorted, count);
	tmp = a;
	while (tmp)
	{
		tmp->index = find_pos(sorted, count, tmp->value);
		if (tmp->index < 0)
			return (free(sorted), 0);
		tmp = tmp->next;
	}
	free(sorted);
	return (1);
}

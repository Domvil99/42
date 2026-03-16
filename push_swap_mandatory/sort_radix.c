/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:08:20 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 17:42:52 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_node **a, t_node **b)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = stack_size(*a);
	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				op_ra(a, 1);
			else
				op_pb(a, b, 1);
			j++;
		}
		while (*b)
			op_pa(a, b, 1);
		i++;
	}
}

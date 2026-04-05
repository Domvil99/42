/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:45:22 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 18:45:53 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	setup_checker_bonus(int argc, char **argv, t_node **a, int **arr)
{
	int	count;

	count = parse_numbers(argc, argv, arr);
	if (count < 0)
		return (-1);
	if (count == 0)
		return (0);
	*a = build_stack(*arr, count);
	if (!*a || !assign_indices(*a, *arr, count))
	{
		free(*arr);
		*arr = NULL;
		free_stack(a);
		return (-1);
	}
	return (1);
}

int	run_checker_bonus(t_node **a, t_node **b)
{
	char	*line;
	int		state;

	state = read_instruction_bonus(&line);
	while (state > 0)
	{
		if (!execute_instruction_bonus(line, a, b))
			return (free(line), 0);
		free(line);
		state = read_instruction_bonus(&line);
	}
	if (state < 0)
		return (0);
	if (is_sorted_stack(*a) && stack_size(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	ready = setup_checker_bonus(argc, argv, &a, &arr);
	if (ready < 0)
		return (print_error(), 1);
	if (ready == 0)
		return (0);
	if (!run_checker_bonus(&a, &b))
		return (free(arr), free_stack(&a), free_stack(&b), print_error(), 1);
	free(arr);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

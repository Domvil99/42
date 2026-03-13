/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 19:25:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	read_instruction(char *line)
{
	int		i;
	char	c;
	ssize_t	ret;

	i = 0;
	while (1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		if (i == 3)
			return (-1);
		line[i++] = c;
	}
	if (ret < 0)
		return (-1);
	if (i == 0 && ret == 0)
		return (0);
	if (i == 0)
		return (-1);
	line[i] = '\0';
	return (1);
}

static int	apply_instruction_a(char *op, t_node **a, t_node **b)
{
	if (!ft_strncmp(op, "sa", 3))
		op_sa(a, 0);
	else if (!ft_strncmp(op, "sb", 3))
		op_sb(b, 0);
	else if (!ft_strncmp(op, "ss", 3))
		op_ss(a, b, 0);
	else if (!ft_strncmp(op, "pa", 3))
		op_pa(a, b, 0);
	else if (!ft_strncmp(op, "pb", 3))
		op_pb(a, b, 0);
	else if (!ft_strncmp(op, "ra", 3))
		op_ra(a, 0);
	else
		return (0);
	return (1);
}

static int	apply_instruction_b(char *op, t_node **a, t_node **b)
{
	if (!ft_strncmp(op, "rb", 3))
		op_rb(b, 0);
	else if (!ft_strncmp(op, "rr", 3))
		op_rr(a, b, 0);
	else if (!ft_strncmp(op, "rra", 4))
		op_rra(a, 0);
	else if (!ft_strncmp(op, "rrb", 4))
		op_rrb(b, 0);
	else if (!ft_strncmp(op, "rrr", 4))
		op_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static int	process_instructions(t_node **a, t_node **b)
{
	char	op[4];
	int		status;

	status = read_instruction(op);
	while (status > 0)
	{
		if (!apply_instruction_a(op, a, b) && !apply_instruction_b(op, a, b))
			return (-1);
		status = read_instruction(op);
	}
	return (status);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		count;
	int		status;

	a = NULL;
	b = NULL;
	arr = NULL;
	count = parse_numbers(argc, argv, &arr);
	if (count < 0)
		return (print_error(), free(arr), free_stack(&a), free_stack(&b), 1);
	if (count == 0)
		return (0);
	a = build_stack(arr, count);
	if (!a || !assign_indices(a, arr, count))
		return (print_error(), free(arr), free_stack(&a), free_stack(&b), 1);
	status = process_instructions(&a, &b);
	if (status < 0)
		return (print_error(), free(arr), free_stack(&a), free_stack(&b), 1);
	if (is_sorted_stack(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(arr), free_stack(&a), free_stack(&b), 0);
}

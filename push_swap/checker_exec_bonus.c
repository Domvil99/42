/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:23:38 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 18:46:37 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	exec_swap_bonus(char *line, t_node **a, t_node **b)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		op_sa(a, 0);
	else if (ft_strncmp(line, "sb", 3) == 0)
		op_sb(b, 0);
	else if (ft_strncmp(line, "ss", 3) == 0)
		op_ss(a, b, 0);
	else
		return (0);
	return (1);
}

static int	exec_push_bonus(char *line, t_node **a, t_node **b)
{
	if (ft_strncmp(line, "pa", 3) == 0)
		op_pa(a, b, 0);
	else if (ft_strncmp(line, "pb", 3) == 0)
		op_pb(a, b, 0);
	else
		return (0);
	return (1);
}

static int	exec_rotate_bonus(char *line, t_node **a, t_node **b)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		op_ra(a, 0);
	else if (ft_strncmp(line, "rb", 3) == 0)
		op_rb(b, 0);
	else if (ft_strncmp(line, "rr", 3) == 0)
		op_rr(a, b, 0);
	else if (ft_strncmp(line, "rra", 4) == 0)
		op_rra(a, 0);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		op_rrb(b, 0);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		op_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	execute_instruction_bonus(char *line, t_node **a, t_node **b)
{
	if (!line || !*line)
		return (0);
	if (exec_swap_bonus(line, a, b))
		return (1);
	if (exec_push_bonus(line, a, b))
		return (1);
	if (exec_rotate_bonus(line, a, b))
		return (1);
	return (0);
}

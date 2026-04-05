/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:46:46 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 19:16:14 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int		parse_numbers(int argc, char **argv, int **out);
int		is_valid_number(const char *s);
long	ps_atol(const char *s, int *ok);

void	print_error(void);
void	free_stack(t_node **stack);
void	free_strtab(char **tab);

t_node	*new_node(int value);
void	add_back_node(t_node **stack, t_node *new_last);
int		stack_size(t_node *stack);
int		is_sorted_stack(t_node *stack);

t_node	*build_stack(int *arr, int count);
int		assign_indices(t_node *a, int *arr, int count);

void	op_sa(t_node **a, int print);
void	op_sb(t_node **b, int print);
void	op_ss(t_node **a, t_node **b, int print);
void	op_pa(t_node **a, t_node **b, int print);
void	op_pb(t_node **a, t_node **b, int print);
void	op_ra(t_node **a, int print);
void	op_rb(t_node **b, int print);
void	op_rr(t_node **a, t_node **b, int print);
void	op_rra(t_node **a, int print);
void	op_rrb(t_node **b, int print);
void	op_rrr(t_node **a, t_node **b, int print);

void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort_chunk(t_node **a, t_node **b);
void	sort_radix(t_node **a, t_node **b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 09:30:15 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 18:34:29 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int	setup_checker_bonus(int argc, char **argv, t_node **a, int **arr);
int	run_checker_bonus(t_node **a, t_node **b);
int	read_instruction_bonus(char **line);
int	execute_instruction_bonus(char *line, t_node **a, t_node **b);

#endif

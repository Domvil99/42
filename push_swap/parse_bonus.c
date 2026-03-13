/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 10:10:00 by saospina          #+#    #+#             */
/*   Updated: 2026/03/13 10:10:00 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	has_duplicates(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_array(char **tokens, int *arr)
{
	int		i;
	int		ok;
	long	value;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			return (-1);
		value = ps_atol(tokens[i], &ok);
		if (!ok)
			return (-1);
		arr[i] = (int)value;
		i++;
	}
	if (has_duplicates(arr, i))
		return (-1);
	return (i);
}

static int	parse_single_string(char *arg, int **out)
{
	char	**split;
	int		*arr;
	int		count;

	if (!arg || !arg[0])
		return (-1);
	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (free_strtab(split), -1);
	count = 0;
	while (split[count])
		count++;
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (free_strtab(split), -1);
	count = fill_array(split, arr);
	free_strtab(split);
	if (count < 0)
		return (free(arr), -1);
	*out = arr;
	return (count);
}

int	parse_numbers(int argc, char **argv, int **out)
{
	int	*arr;
	int	count;

	*out = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		return (parse_single_string(argv[1], out));
	count = argc - 1;
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (-1);
	count = fill_array(&argv[1], arr);
	if (count < 0)
		return (free(arr), -1);
	*out = arr;
	return (count);
}

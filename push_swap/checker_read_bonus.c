/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:35:51 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 18:49:13 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	grow_buffer_bonus(char **buf, size_t *cap)
{
	char	*new_buf;
	size_t	old_cap;

	old_cap = *cap;
	*cap *= 2;
	new_buf = malloc(*cap);
	if (!new_buf)
		return (0);
	ft_memcpy(new_buf, *buf, old_cap);
	free(*buf);
	*buf = new_buf;
	return (1);
}

static ssize_t	read_loop_bonus(char **buf, size_t *len, size_t *cap, char *c)
{
	ssize_t	rd;

	rd = read(0, c, 1);
	while (rd > 0)
	{
		if (*c == '\n')
			break ;
		if (*len + 1 >= *cap && !grow_buffer_bonus(buf, cap))
			return (-1);
		(*buf)[(*len)++] = *c;
		rd = read(0, c, 1);
	}
	return (rd);
}

int	read_instruction_bonus(char **line)
{
	char	*buf;
	size_t	len;
	size_t	cap;
	char	c;
	ssize_t	rd;

	buf = malloc(16);
	if (!buf)
		return (-1);
	len = 0;
	cap = 16;
	rd = read_loop_bonus(&buf, &len, &cap, &c);
	if (rd < 0 || (rd == 0 && len > 0))
		return (free(buf), -1);
	if (rd == 0 && len == 0)
		return (free(buf), 0);
	buf[len] = '\0';
	*line = buf;
	return (1);
}

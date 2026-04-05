/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 04:09:32 by saospina          #+#    #+#             */
/*   Updated: 2025/10/03 17:58:54 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	copy_line(char *line, char *stash, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[i + 1] = '\0';
	else
		line[i] = '\0';
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	extra;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	extra = 1;
	if (stash[i] == '\n')
		extra = 2;
	line = malloc(i + extra);
	if (!line)
		return (NULL);
	copy_line(line, stash, i);
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

/*
int main(void)
{
	char *line;

	int fd1 = open("archivo1.txt", O_RDONLY);
	int fd2 = open("archivo2.txt", O_RDONLY);
	int fd3 = open("archivo3.txt", O_RDONLY);

	if(fd1 < 0 || fd2 < 0 || fd3 < 0 )
	{
		perror("erroe");
		return(1);
	}
	while((line = get_next_line(fd1)) != NULL)
	{
		printf("FD1:%s",line);
		free(line);
	}
	while((line = get_next_line(fd2)) != NULL)
	{
		printf("FD2:%s",line);
		free(line);
	}
	while((line = get_next_line(fd3)) != NULL)
	{
		printf("FD3:%s",line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return(0);
}
*/
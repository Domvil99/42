/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 04:10:09 by saospina          #+#    #+#             */
/*   Updated: 2025/10/03 17:58:27 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

static char	*update_buffer(char *buffer)
{
	size_t	i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + i + (buffer[i] == '\n'));
	free(buffer);
	return (new_buffer);
}

static char	*read_and_append(int fd, char *buffer)
{
	ssize_t	bytes_read;
	char	*chunk;

	chunk = (char *)malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(chunk);
			free(buffer);
			return (NULL);
		}
		chunk[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, chunk);
	}
	free(chunk);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_append(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

/*
int main(void)
{
	char	*line; 
	int		fd;

	fd = open("archivo.txt", O_RDONLY);
	if(fd == -1)
	{	
		perror("err");
		return(1);
	}
	while((line = get_next_line(fd)) != NULL)
	{ 
		printf("Linea: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
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
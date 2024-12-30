/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:41:43 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/29 10:29:47 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(void *str1, void *str2)
{
	int	i;

	i = 0;
	if (str1)
		free (str1);
	if (str2)
	{
		while (str2[i])
			free(str2[i++]);
		free(str2);
	}
}

static char	*read_file(int fd, char *buffer)
{
	char	*old_buffer;
	int		bytes_read;

	old_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!old_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		ft_memset(old_buffer, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, old_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(old_buffer, &buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, old_buffer);
		if (!buffer)
		{
			free(old_buffer);
			return (NULL);
		}
	}
	free(old_buffer);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	ft_memset(line, 0, i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	ft_memset(new_buffer, 0, ft_strlen(buffer) - i + 1);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd <= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

// #include <fcntl.h> // open & close

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (line != NULL && i != 10)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
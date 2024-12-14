/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:41:43 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/14 16:41:37 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	lineiscomplete(int pos_n, int fd, char *buffer, char **line)
{
	int			bytes_read;

	pos_n = islinecomplete(*line);
	while (pos_n == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			// buffer[0] = '\0';
			if (*line && **line)
				return (islinecomplete(buffer));
			break ;
		}
		buffer[bytes_read] = '\0';
		printf("[%c]\n", buffer[bytes_read]);
		if (ft_strchr(buffer, '\n') == -1)
		{
			*line = ft_strnjoin(*line, buffer, bytes_read);
			if (!*line)
				return (-2);
		}
		pos_n = islinecomplete(buffer);
	}
	return (pos_n);
}

char	*ft_free(char *leftover)
{
	free (leftover);
	leftover = NULL;
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*leftover = NULL;
	int			pos_n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	pos_n = -1;
	if (leftover)
	{
		line = ft_strnjoin(line, leftover, ft_strlen(leftover));
		leftover = ft_free(leftover);
	}
	pos_n = lineiscomplete(pos_n, fd, buffer, &line);
	if (pos_n == -2)
		return (NULL);
	if (pos_n > -1)
	{
		int len = ft_strlen(buffer); // problem
		printf("Size : [%s]\n", buffer);
		line = ft_strnjoin(line, buffer, pos_n); // buffer empty
		if (!line)
			return (NULL);
		leftover = ft_strnjoin(NULL, buffer + pos_n + 1, len - pos_n);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL && i != 10)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
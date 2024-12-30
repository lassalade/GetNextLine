/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:04:23 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/20 19:03:26 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd/*, char **line*/, char *buffer, int bytes_read); // add char **line pour faire un ft_leftover(leftover = buffer after \n) and  ......... buffer = leftover + new buffer

char	*ft_get_line(char *buffer) // get line = buffer * n until \n
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_strnjoin(NULL, buffer + i + 1, BUFFER_SIZE - i);
	return (line);
}

char	*ft_clean_buffer(char *buffer); // clean buffer before each read

char	*get_next_line(int fd) // 
{
	static char	*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer, 1);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	tmp = buffer;
	buffer = ft_leftover(buffer);
	free(tmp);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:41:43 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/29 12:28:34 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void *str1, void *str2)
{
	if (str1)
		free (str1);
	if (str2)
	free (str2);
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
			ft_free(old_buffer, buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, old_buffer); //utiliser un strnjoin avec la pos du \n pour optimiser (creer un fonction find_newline)
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

// #include <stdio.h> // printf
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

/* 


<< PLUS OPTIMISE >>


#include <stdlib.h> // For malloc, free
#include <unistd.h> // For read
#include <string.h> // For strlen, memmove

#define BUFFER_SIZE 1024

// Helper function to find the newline character in a string
static char *find_newline(char *s)
{
    while (*s)
    {
        if (*s == '\n')
            return s;
        s++;
    }
    return NULL;
}

// Helper function to join two strings with a given length
static char *strjoin_len(const char *s1, const char *s2, size_t len2)
{
    size_t len1 = strlen(s1);
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    memmove(result, s1, len1);
    memmove(result + len1, s2, len2);
    result[len1 + len2] = '\0';
    return result;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static char *leftover = NULL;
    char *line = NULL;
    char *newline_pos;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    if (leftover)
    {
        newline_pos = find_newline(leftover);
        if (newline_pos)
        {
            *newline_pos = '\0';
            line = strdup(leftover);
            memmove(leftover, newline_pos + 1, strlen(newline_pos + 1) + 1);
            return line;
        }
        line = strdup(leftover);
        free(leftover);
        leftover = NULL;
    }
    else
    {
        line = strdup("");
    }

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        newline_pos = find_newline(buffer);
        if (newline_pos)
        {
            *newline_pos = '\0';
            char *temp = strjoin_len(line, buffer, newline_pos - buffer);
            free(line);
            line = temp;
            leftover = strdup(newline_pos + 1);
            return line;
        }
        else
        {
            char *temp = strjoin_len(line, buffer, bytes_read);
            free(line);
            line = temp;
        }
    }

    if (bytes_read < 0 || (bytes_read == 0 && line[0] == '\0'))
    {
        free(line);
        return NULL;
    }

    return line;
}*/
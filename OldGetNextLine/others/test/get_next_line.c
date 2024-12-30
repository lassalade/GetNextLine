/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:57:40 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/20 15:04:29 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_check_buffer(t_newline *nl, char *buffer)
{
	if (!buffer)
		return (-1);
	nl->pos_n = ft_str_indexof(buffer, '\n');
	if (!nl->line)
		nl->check = ft_strndup(nl, buffer, nl->pos_n);
	else
		nl->check = ft_strnjoin(nl, nl->line, buffer, nl->pos_n);
	if (!nl->line) // geré si absence de char * ou si erreur de malloc (-1) ou (NULL) ?
		return (-1);
	else
		return (0);
}

int	ft_check_leftover(t_newline *nl, char *leftover)
{
	nl->check = ft_check_buffer(nl, leftover);
	if (leftover) // && nl->line ??
		free (leftover);
	return (BUFFER_SIZE);
}

// int	ft_alloc_and_cpy(t_newline *nl)
// {
// 	int	count;

// 	count = 0;
// 	if (!nl->line)
// 		count = ft_strdup();
// 	else
// 		count = ft_strnjoin();
// 	return (count);
// }

void	ft_initial_struct(t_newline *nl)
{
	nl->line = NULL;
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	t_newline	nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	nl.check = ft_check_leftover(&nl, leftover);
	if (nl.pos_n == -1 || nl.check != 0)
		return (NULL);
	while (nl.pos_n >= 0 && nl.pos_n <= BUFFER_SIZE)
	{
		nl.pos_n = ft_str_indexof(leftover, '\n');
		nl.bytes_read = read(fd, nl.buffer, BUFFER_SIZE);
		if (nl.bytes_read <= 0)
		{
			if (nl.line && *nl.line)
				return (nl.line);
			break ;
		}
		nl.buffer[nl.bytes_read] = '\0';
		nl.check = ft_check_buffer(&nl, nl.buffer);
		if (nl.pos_n == -1 || nl.check != 0)
			return (NULL);
	}
	return (nl.line);
}
	// if (nl->pos_n > -1 /*function*/&& nl->bytes_read != 0)
	// //blabla

#include <fcntl.h>
int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file");
		return (-1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd);
	return (0);
}

	printf("%s\n", "Machin\n");
	printf("%s\n", "Truc\n");
	printf("%s\n", "Chose\n");
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/29 12:42:13 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		fd[ac - 1];
	char	*lines[ac - 1];
	int		files_left;
	int		i;

	if (ac == 1)
	{
		char	*line_std;

		printf("CTRL+D pour terminer (CTRL+C kill the program):\n");
		while ((line_std = get_next_line(0)) != NULL)
		{
			printf("%s", line_std);
			free(line_std);
		}
		return (0);
	}
	files_left = 0;
	for (i = 1; i < ac; i++)
	{
		fd[i - 1] = open(av[i], O_RDONLY);
		if (fd[i - 1] == -1)
		{
			lines[i - 1] = get_next_line(fd[i - 1]);
			printf("File %d: %s\n", i, lines[i - 1]);
			continue ;
		}
		lines[i - 1] = get_next_line(fd[i - 1]);
		if (!lines[i - 1])
		{
			printf("File %d is empty or reading failed.\n", i);
			lines[i - 1] = get_next_line(fd[i - 1]);
			printf("File %d: %s\n", i, lines[i - 1]);        
			close(fd[i - 1]);
			files_left--;
		}
		else
			files_left++;
	}
	while (files_left > 0)
	{
		for (i = 0; i < ac - 1; i++)
		{
			if (lines[i])
			{
				printf("File %d: %s", i, lines[i]);
				free(lines[i]);
				lines[i] = get_next_line(fd[i]);
				if (!lines[i])
				{
					close(fd[i]);
					files_left--;
				}
			}
		}
	}
	return (0);
}

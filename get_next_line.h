/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:58:28 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/15 19:51:27 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <stdio.h>
# include <unistd.h>

typedef struct s_newline
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	int			pos_n;
}	t_newline;

int		strindexof(char *s, char c);

char	*get_next_line(int fd);

#endif
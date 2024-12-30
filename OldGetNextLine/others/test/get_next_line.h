/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:58:28 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/20 14:28:48 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_newline
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1]; // pas un char *buffer puisque tableau
	int			bytes_read;
	int			pos_n;
	int			check;
}	t_newline;

int		ft_str_indexof(char *s, char c);
int		ft_strnjoin(char *dest, char *src, int end);
int		ft_strndup(char *src, int end);
int		ft_strlen(char *s);

char	*get_next_line(int fd);

#endif
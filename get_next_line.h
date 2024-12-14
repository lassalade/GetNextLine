/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:42:25 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/14 16:19:13 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# define BUFFER_SIZE 150

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strnjoin(char *line, char *buffer, int n);
int		islinecomplete(char *s);

char	*get_next_line(int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:42:25 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/28 18:44:23 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> // read
# include <stdlib.h> // malloc & free
# include <stdio.h> // FOPEN_MAX

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

# ifndef MAX_FD
#  define MAX_FD FOPEN_MAX
# endif

int		ft_strlen(char *s);
char	*ft_strjoin(char **line, char *buffer);
char	*ft_strchr(char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(char *s);

char	*get_next_line(int fd);

#endif
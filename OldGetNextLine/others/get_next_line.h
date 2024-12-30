/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:04:42 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/20 18:54:46 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h> // read & size_t
# include <stdlib.h> // malloc & free
# include <fcntl.h> // open & close
# include <stdio.h> // printf

char	*get_next_line(int fd);

#endif
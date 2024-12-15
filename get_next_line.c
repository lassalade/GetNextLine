/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:57:40 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/15 19:51:24 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_isnewline(char *leftover)
{

}

int	check_leftover(t_newline *nl, char *leftover)
{
	if (!leftover)
		return (-1);
	else
	{
		if (!nl->line)
			ft_strndup(leftover, nl->pos_n); //calculer pos_n pour trouver index \n ou taille de BUFFER_SIZE
		else
			ft_strnjoin(nl->line, leftover, nl->pos_n);
		if (!nl->line)
			return (-1);
	}
	if (nl->line && leftover)
		free (leftover);
	return (0);
}

int	ft_alloc_and_cpy(t_newline *nl)
{
	int	count;

	count = 0;
	if (!nl->line)
		count = ft_strdup();
	else
		count = ft_strnjoin();
	return (count);
}

void	initial_struct(t_newline *nl, char *leftover)
{
	nl->line = NULL;
	nl->pos_n = ft_isnewline(leftover); //return -1 si leftover null
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	t_newline	*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	initial_struct(nl, leftover);
	check_leftover(nl, leftover);
	while (nl->pos_n == -1)
	{
		nl->bytes_read = read(fd, nl->buffer, BUFFER_SIZE);
		if (nl->bytes_read <= 0)
		{
			if (nl->line && *nl->line)
				return (nl->bytes_read);
			break ;
		}
		nl->buffer[nl->bytes_read] = '\0';
		//function
	}
	if (nl->pos_n > -1 /*function*/&& nl->bytes_read != 0)
	//blabla
	return (nl->line);
}

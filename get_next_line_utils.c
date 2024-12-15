/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:16:19 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/15 19:20:52 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (-1);
	while (s[len])
		len++;
	return (len);
}

int	ft_strindexof(char *s, char c)
{
	int	i;

	if (!s)
		return (-2);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strndup()
{

}

int	ft_strnjoin()
{}
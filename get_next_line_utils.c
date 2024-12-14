/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:42:30 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/14 16:23:46 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		new_str = malloc(sizeof(char) * n + 2);
	else
		new_str = malloc(sizeof(char) * ft_strlen(s1) + n + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	j = 0;
	while (j <= n && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strchr(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
		{
			return (i);
		}
		i++;
	}
	if ((unsigned char) s[i] == (unsigned char) c)
		return (i);
	return (-1);
}

int	islinecomplete(char *s)
// int	strindexof(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:56:40 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/04 21:57:45 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		replace_c(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			return (i);
		}
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			n;
	static int	res = 0;
	static char	buff[BUFF_SIZE + 1];

	*line = ft_strnew(BUFF_SIZE);
	if (res == -1)
		return (0);
	if (res != 0)
		*line = ft_strcpy(*line, &buff[res + 1]);
	if ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		res = replace_c(buff);
		*line = ft_strjoin(*line, buff);
	}
	if (n == 0)
	{
		if (*line[0] == 0)
			return (0);
		res = -1;
	}
	if (n == -1)
		return (-1);
	return (1);
}

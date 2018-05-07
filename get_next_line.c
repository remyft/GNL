/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:56:40 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/08 01:33:12 by rfontain         ###   ########.fr       */
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
	static t_buff	buffer;

	*line = ft_strnew(BUFF_SIZE);
	if (buffer.res == -1)
		return (0);
	if (buffer.buff[0])
		*line = ft_strcpy(*line, &(buffer.buff)[buffer.res + 1]);
	if ((n = read(fd, buffer.buff, BUFF_SIZE)) > 0)
	{
		buffer.buff[n] = '\0';
		buffer.res = replace_c(buffer.buff);
		*line = ft_strjoin(*line, buffer.buff);
	}
	if (n == 0)
	{
		if (*line[0] == 0)
			return (0);
		buffer.res = -1;
	}
	if (n == -1)
		return (-1);
	return (1);
}

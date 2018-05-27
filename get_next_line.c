/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:56:40 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/27 17:16:56 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					read_line(int fd, t_list *file)
{
	char	buff[BUFF_SIZE + 1];
	int		n;

	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		if (!(file->content = ft_strjoin(file->content, buff)))
			return (-1);
		if (ft_occuc(buff, '\n'))
			break ;
	}
	return (1);
}

static t_list		*check_fd(int fd, t_list **file)
{
	t_list		*ret;

	ret = *file;
	while (ret)
	{
		if ((int)ret->content_size == fd)
			return (ret);
		ret = ret->next;
	}
	ret = ft_lstnew("\0", fd);
	ft_lstadd(file, ret);
	ret = *file;
	return (ret);
}

static char			*ft_realloc(char *str1, char *str2)
{
	str1 = ft_strnew(ft_strlen(str2));
	str1 = ft_strcpy(str1, str2);
	free(str2);
	return (str1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list			*file;
	int						n;
	t_list					*current;
	char					*tmp;

	if (fd < 0 || line == NULL || read(fd, line, 0) < 0)
		return (-1);
	current = check_fd(fd, &file);
	if (!(read_line(current->content_size, current)))
		return (-1);
	if (!(ft_strlen(current->content)))
		return (0);
	*line = ft_strnew(1);
	n = ft_copyuntil(line, current->content, '\n');
	if (n < (int)ft_strlen(current->content))
	{
		tmp = ft_strnew(ft_strlen((current->content + n + 1)));
		tmp = ft_strcpy(tmp, (current->content + n + 1));
		free(current->content);
		current->content = ft_realloc(current->content, tmp);
	}
	else
		ft_strclr(current->content);
	return (1);
}

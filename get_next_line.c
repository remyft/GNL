/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:56:40 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/17 23:15:17 by rfontain         ###   ########.fr       */
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

static t_list		*find_in_list(int fd, t_list **file)
{
	t_list	*ret;

	ret = *file;
	while (ret)
	{
		if ((int)ret->content_size == fd)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

static t_list		*check_fd(int fd, t_list **file)
{
	t_list		*ret;

	if ((ret = find_in_list(fd, file)))
		return (ret);
	ret = ft_lstnew("\0", fd);
	ft_lstadd(file, ret);
	ret = *file;
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_list			*file;
	int						n;
	t_list					*current;

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
		current->content += n + 1;
	else
		ft_strclr(current->content);
	return (1);
}

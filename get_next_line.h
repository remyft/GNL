/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:56:40 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/27 17:37:09 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define ERROR(x) ft_putstr(x)

# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>

int		read_line(int fd, t_list *current);
int		get_next_line(int const fd, char **line);
void	ft_getout(char *error);

#endif

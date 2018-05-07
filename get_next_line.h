/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:55:03 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/08 00:54:37 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

#define BUFF_SIZE 32

typedef struct		s_buff
{
	char buff[BUFF_SIZE + 1];
	int res;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif

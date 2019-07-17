/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 02:17:39 by rfontain          #+#    #+#             */
/*   Updated: 2019/07/17 02:43:33 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	if (!av[1] || (fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("No such file\nUsage : ./GNL PathToFile\n");
		return (1);
	}
	while ((get_next_line(fd, &line)) == 1)
	{
		printf("%d : %s\n", i, line);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:56:36 by rfontain          #+#    #+#             */
/*   Updated: 2018/05/08 01:06:57 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fdIn;
	char	*recup1;
	int		i = 0;

	if (ac == 2)
	{
		fdIn = open(av[1], O_RDONLY);
		while ((i = get_next_line(fdIn, &recup1)))
		{
			ft_putstr(recup1);
			ft_putstr("\n");
		}
	}
	close(fdIn);
	return (0);
}

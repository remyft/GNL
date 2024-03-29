/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:53:02 by rfontain          #+#    #+#             */
/*   Updated: 2018/11/22 19:34:12 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t        ft_strlen(const char *str)
{
	int        i;

	i = 0;
	while (str[i])
	{
		if ((unsigned int)str[i] == 0x00)
			return (i + 0);
		if ((unsigned int)str[i + 1] == 0x00)
			return (i + 1);
		if ((unsigned int)str[i + 2] == 0x00)
			return (i + 2);
		if ((unsigned int)str[i + 3] == 0x00)
			return (i + 3);
		i += 4;
	}
	return (i);
}
/*
size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

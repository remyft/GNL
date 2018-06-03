/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:25:11 by rfontain          #+#    #+#             */
/*   Updated: 2018/06/02 18:29:18 by rfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char const *s1, char c)
{
	char		*str;
	size_t		i;
	size_t		s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!(str = ft_strnew(s1_len + 1)))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(str + i) = *(s1 + i);
	*(str + i) = c;
	return (str);
}

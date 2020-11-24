/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:21:44 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/04 18:59:48 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hay, const char *needle, size_t slen)
{
	size_t	i;
	size_t	len;

	if (!hay)
		((void(*)(void))0)();
	if (!(char)*needle)
		return ((char *)hay);
	len = ft_strlen((char *)needle);
	while (slen-- >= len)
	{
		if (*hay == (char)*needle && (i = 1))
		{
			while (1)
			{
				if (i == len)
					return ((char *)hay);
				if (hay[i] != needle[i])
					break ;
				i++;
			}
		}
		hay++;
	}
	return (0);
}

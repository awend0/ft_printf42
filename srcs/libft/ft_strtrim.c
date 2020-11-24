/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:16:55 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/02 17:40:22 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*ret;
	char	*end;

	if (!s1 || !set)
		return (0);
	end = (char*)(s1 + ft_strlen((char *)s1)) - 1;
	while (ft_isset(*s1, set))
		s1++;
	if (s1 >= end)
		return (ft_strnew(0));
	while (ft_isset(*end, set))
		end--;
	end++;
	str = ft_strnew(end - s1);
	if (!str)
		return (0);
	ret = str;
	while (s1 != end)
		*str++ = *s1++;
	return (ret);
}

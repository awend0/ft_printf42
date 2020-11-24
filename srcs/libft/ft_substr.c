/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:57:07 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/02 17:17:21 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	char	*ret;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen((char *)s) <= start)
		return (ft_strnew(0));
	str = ft_strnew(len);
	if (!str)
		return (0);
	ret = str;
	s += start;
	while (*s && len--)
		*str++ = *s++;
	return (ret);
}

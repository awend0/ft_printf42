/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:56:27 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/04 18:57:56 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

size_t		ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	result_len;

	dst_len = ft_strlen(dst);
	result_len = ft_min(dstsize, dst_len) + ft_strlen(src);
	if (!(dstsize <= dst_len))
	{
		dst += dst_len;
		dstsize -= dst_len;
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (result_len);
}

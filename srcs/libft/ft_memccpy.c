/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:30:57 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/04 18:53:24 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	sym;

	sym = (unsigned char)c;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (n--)
	{
		*dest++ = *source++;
		if (*(dest - 1) == sym)
			return (dest);
	}
	return (0);
}

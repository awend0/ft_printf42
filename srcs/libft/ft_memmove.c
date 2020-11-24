/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:19:22 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/01 18:06:36 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	if (dst > src)
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

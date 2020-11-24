/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:43:50 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/02 16:55:32 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	unsigned int	nbr;
	int				neg;
	int				res;

	res = 1;
	neg = (n < 0) ? 1 : 0;
	nbr = (neg) ? n * -1 : n;
	nbr /= 10;
	while (nbr)
	{
		nbr /= 10;
		res++;
	}
	return ((neg) ? res + 1 : res);
}

char		*ft_itoa(int n)
{
	char			*s;
	char			*s1;
	int				neg;
	unsigned int	nbr;
	int				len;

	neg = (n < 0) ? 1 : 0;
	nbr = (neg) ? n * -1 : n;
	len = ft_nbrlen(n);
	s = ft_strnew(len);
	if (!s)
		return (0);
	s1 = s;
	s = s + len - 2;
	*(s1 + len - 1) = nbr % 10 + '0';
	nbr /= 10;
	while (nbr)
	{
		*s = nbr % 10 + '0';
		nbr /= 10;
		s--;
	}
	(neg) ? *s = '-' : (void)0;
	return (s1);
}

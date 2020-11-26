/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 01:46:06 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static void		ft_oct4(wint_t c)
{
	unsigned char toprint[4];

	toprint[0] = (c >> 18) + 240;
	toprint[1] = ((c >> 12) & 63) + 128;
	toprint[2] = ((c >> 6) & 63) + 128;
	toprint[3] = ((c & 63) + 128);
	write(1, toprint, 4);
}

static void		ft_oct3(wint_t c)
{
	unsigned char toprint[3];

	toprint[0] = (c >> 12) + 224;
	toprint[1] = ((c >> 6) & 63) + 128;
	toprint[2] = ((c & 63) + 128);
	write(1, toprint, 3);
}

static void		ft_oct2(wint_t c)
{
	unsigned char toprint[2];

	toprint[0] = (c >> 6) + 192;
	toprint[1] = ((c & 63) + 128);
	write(1, toprint, 2);
}

static void		ft_oct1(wint_t c)
{
	write(1, &c, 1);
}

int				ft_display_wchar(wint_t c)
{
	int		len;

	if (c <= 127)
	{
		len = 1;
		ft_oct1(c);
	}
	if (c >= 127 && c <= 2047)
	{
		len = 2;
		ft_oct2(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		len = 3;
		ft_oct3(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		len = 4;
		ft_oct4(c);
	}
	return (len);
}

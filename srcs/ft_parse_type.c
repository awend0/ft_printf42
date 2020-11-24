/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:01:23 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/23 11:25:02 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

char	ft_parse_type(const char *format)
{
	const char	types[14] = "%cspdiuxXnfge";
	char		*tmp;
	int			i;

	i = 0;
	while (types[i])
	{
		if ((tmp = ft_strchr((char*)(format + 1), types[i])))
			return (*tmp);
		i++;
	}
	return (0);
}

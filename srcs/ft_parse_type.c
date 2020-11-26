/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:01:23 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/25 20:03:46 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

char	ft_parse_type(const char *format)
{
	const char	types[14] = "%cspdiuxXnfge";

	format++;
	while (*format)
	{
		if (ft_strchr((char*)types, (char)*format))
			return ((char)*format);
		format++;
	}
	return (0);
}

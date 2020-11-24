/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/23 15:10:04 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

unsigned char	ft_parse_flags(const char **format, t_tab *tab)
{
	unsigned char	flags;

	flags = FLG_NONE;
	*format += 1;
	while (**format && **format != tab->type && !(**format == '1' ||
	**format == '2' || **format == '3' || **format == '4' || **format == '5' ||
	**format == '6' || **format == '7' || **format == '8' || **format == '9' ||
	**format == '*' || **format == '.' || **format == 'l' || **format == 'h'))
	{
		if (**format == '-')
			flags = flags | FLG_MINUS;
		if (**format == '+')
			flags = flags | FLG_PLUS;
		if (**format == ' ')
			flags = flags | FLG_SPACE;
		if (**format == '#')
			flags = flags | FLG_HASH;
		if (**format == '0')
			flags = flags | FLG_ZERO;
		(*format)++;
	}
	return (flags);
}

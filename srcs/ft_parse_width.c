/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/23 15:21:59 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int		ft_parse_width(const char **format, t_tab *tab)
{
	int		width;

	width = 0;
	if (**format == '*')
		width = -2;
	while (**format != tab->type && **format != '.'
			&& **format != 'l' && **format != 'h')
	{
		if (ft_isdigit(**format))
			width = width * 10 + **format - '0';
		(*format)++;
	}
	return (width);
}

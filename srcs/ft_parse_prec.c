/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/23 15:19:32 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int		ft_parse_prec(const char **format, t_tab *tab)
{
	int		prec;

	prec = 0;
	if (**format == '.' &&
		(ft_isdigit(*(*format + 1)) || *(*format + 1) == '*'))
	{
		(*format) += 1;
		if (**format == '*')
			return (-2);
		while (**format != tab->type && **format != '.'
				&& **format != 'h' && **format != 'l')
		{
			if (ft_isdigit(**format))
				prec = prec * 10 + **format - '0';
			(*format)++;
		}
	}
	return (prec);
}

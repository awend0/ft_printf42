/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:10:28 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

void	ft_init_tab(t_tab *tab)
{
	tab->tmp = 0;
	tab->flags = FLG_NONE;
	tab->len = 0;
	tab->precision = 0;
	tab->type = 0;
	tab->width = 0;
	tab->negw = 0;
	tab->negp = 0;
}

int		ft_parser(const char **format, t_tab *tab)
{
	int		res;
	int		len;

	ft_init_tab(tab);
	len = 0;
	if ((tab->type = ft_parse_type(*format)) == 0)
		return (-1);
	if ((tab->flags = ft_parse_flags(format, tab)) == FLG_ERROR)
		return (-1);
	if ((tab->width = ft_parse_width(format, tab)) == -1)
		return (-1);
	if ((tab->precision = ft_parse_prec(format, tab)) == -1)
		return (-1);
	if ((tab->len = ft_parse_len(format, tab)) == 'E')
		return (-1);
	res = ft_processor(tab);
	(*format)++;
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}

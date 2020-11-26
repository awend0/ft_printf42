/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:10:54 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

t_tab	*ft_handle_star(t_tab *tab)
{
	if (tab->width == -2)
	{
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->width *= -1;
			tab->flags = tab->flags | FLG_MINUS;
			tab->negw = 1;
		}
	}
	if (tab->precision == -2)
	{
		tab->precision = va_arg(tab->args, int);
		if (tab->precision < 0)
			tab->negp = 1;
		if (tab->precision <= 0)
			tab->precision = -3;
	}
	return (tab);
}

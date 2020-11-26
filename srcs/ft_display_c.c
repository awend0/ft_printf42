/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:11:33 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int		ft_display_c(t_tab *tab)
{
	wint_t		c;
	int			len;

	len = 0;
	tab = ft_handle_star(tab);
	if (tab->len == 'l')
		c = (unsigned long)va_arg(tab->args, unsigned long);
	else
		c = (wint_t)va_arg(tab->args, int);
	c = (wint_t)c;
	if (tab->flags & FLG_ZERO && !(tab->flags & FLG_MINUS) && !tab->negw)
		len += ft_display_gap(tab->width - 1, '0');
	else if (!(tab->flags & FLG_MINUS))
		len += ft_display_gap(tab->width - 1, ' ');
	len += ft_display_wchar(c);
	if (tab->flags & FLG_MINUS)
		len += ft_display_gap(tab->width - 1, ' ');
	return (len);
}

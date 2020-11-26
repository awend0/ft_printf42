/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:26:41 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static char	*ft_handle_null(t_tab *tab, char *s)
{
	if (tab->precision > 0 && s)
		return (ft_strndup(s, tab->precision));
	else if (tab->precision == -3 && !tab->negw && !tab->negp)
		return (ft_strdup("\0"));
	else if (!s && ((tab->precision >= 6 || tab->precision == 0)
	|| (tab->precision == -3 && tab->negp)))
		return (ft_strdup("(null)"));
	else if (!s)
		return (ft_strdup("\0"));
	return (s);
}

int			ft_display_s(t_tab *tab)
{
	char		*s;
	int			len;

	tab = ft_handle_star(tab);
	s = va_arg(tab->args, void *);
	s = ft_handle_null(tab, s);
	len = ft_strlen(s);
	if (tab->flags & FLG_ZERO && !(tab->flags & FLG_MINUS) && !tab->negw)
		len += ft_display_gap(tab->width - len, '0');
	else if (!(tab->flags & FLG_MINUS))
		len += ft_display_gap(tab->width - len, ' ');
	ft_putstr_fd(s, 1);
	(tab->flags & FLG_MINUS) ?
	(len += ft_display_gap(tab->width - len, ' ')) : 0;
	return (len);
}

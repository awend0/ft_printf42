/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 04:26:43 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static int		ft_print_p(t_tab *tab, char *str, int leftalign)
{
	int		tofill;
	int		vallen;
	int		len;

	vallen = ft_strlen(str) + 2;
	tofill = vallen;
	len = (tofill <= tab->width) ? tab->width : tofill;
	if (!leftalign)
		ft_display_gap(tab->width - tofill, ' ');
	write(1, "0x", 2);
	(!tab->negw) ? (len += ft_display_gap(tab->precision - vallen, '0')) : 0;
	ft_putstr_fd(str, 1);
	if (leftalign)
		ft_display_gap(tab->width - tofill, ' ');
	free(str);
	return (len);
}

int				ft_display_p(t_tab *tab)
{
	char		*str;
	uintmax_t	n;
	int			leftalign;

	leftalign = (tab->flags & FLG_MINUS) ? 1 : 0;
	tab = ft_handle_star(tab);
	n = (uintmax_t)(unsigned long)va_arg(tab->args, unsigned long int);
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (!(str = ft_itoa_base(n, 16)))
		return (-1);
	if (tab->precision == -3 && n == 0)
		*str = 0;
	if (tab->flags & FLG_ZERO && tab->precision == 0 && !leftalign)
	{
		tab->precision = tab->width - 2;
		tab->width = 0;
	}
	return (ft_print_p(tab, str, leftalign));
}

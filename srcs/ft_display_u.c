/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:15:22 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static int			ft_numlen(uintmax_t n)
{
	int				res;

	res = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static uintmax_t	ft_get_num(t_tab *tab)
{
	uintmax_t	num;

	if (tab->len == 'H')
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (tab->len == 'h')
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (tab->len == 'L')
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (tab->len == 'l')
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			ft_print_u(t_tab *tab, uintmax_t value, int vallen)
{
	int		leftalign;
	int		tofill;
	int		len;

	leftalign = (tab->flags & FLG_MINUS) ? 1 : 0;
	tofill = vallen;
	if (vallen <= tab->precision && tab->precision >= 0)
		tofill = tab->precision;
	tofill += tab->tmp;
	len = (tofill <= tab->width) ? tab->width : tofill;
	if (!leftalign && (!(tab->flags & FLG_ZERO) ||
	((tab->flags & FLG_ZERO) && tab->precision > 0 && tab->width > tofill)))
		ft_display_gap(tab->width - tofill, ' ');
	(!tab->negw) ? (len += ft_display_gap(tab->precision - vallen, '0')) : 0;
	if (tab->flags & FLG_ZERO && tab->precision == 0 && !tab->negw)
		ft_display_gap(tab->width - tofill, '0');
	ft_putnbr_fd(value, 1);
	if (leftalign)
		ft_display_gap(tab->width - tofill, ' ');
	return (len);
}

int					ft_display_u(t_tab *tab)
{
	uintmax_t	value;
	int			vallen;

	tab = ft_handle_star(tab);
	value = ft_get_num(tab);
	vallen = ft_numlen(value);
	tab->tmp = (tab->flags & FLG_PLUS || tab->flags & FLG_SPACE) ? 1 : 0;
	if (value == 0 && tab->precision == -3 && !tab->negp)
	{
		(tab->flags & FLG_PLUS) ? ft_putchar_fd('+', 1) : 0;
		(tab->flags & FLG_SPACE) ? ft_putchar_fd(' ', 1) : 0;
		ft_display_gap(tab->width, ' ');
		return (tab->width);
	}
	return (ft_print_u(tab, value, vallen));
}

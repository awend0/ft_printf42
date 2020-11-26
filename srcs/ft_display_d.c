/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:15:09 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static int		ft_numlen(intmax_t n)
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

static intmax_t	ft_get_num(t_tab *tab)
{
	intmax_t	num;

	if (tab->len == 'H')
		num = (signed char)(va_arg(tab->args, int));
	else if (tab->len == 'h')
		num = (short)(va_arg(tab->args, int));
	else if (tab->len == 'L')
		num = (intmax_t)(va_arg(tab->args, long long int));
	else if (tab->len == 'l')
		num = (long)(va_arg(tab->args, long int));
	else
		num = (int)(va_arg(tab->args, int));
	num = (intmax_t)num;
	return (num);
}

static char		ft_get_additional(t_tab *tab, int is_negative)
{
	if (is_negative)
		return ('-');
	if (tab->flags & FLG_PLUS)
		return ('+');
	if (tab->flags & FLG_SPACE)
		return (' ');
	return (0);
}

static int		ft_print_d(t_tab *tab, intmax_t value,
				int vallen, int is_negative)
{
	int		leftalign;
	int		tofill;
	char	add;
	int		len;

	add = ft_get_additional(tab, is_negative);
	leftalign = (tab->flags & FLG_MINUS) ? 1 : 0;
	tofill = vallen;
	if (vallen <= tab->precision && tab->precision >= 0)
		tofill = tab->precision;
	tofill += tab->tmp;
	len = (tofill <= tab->width) ? tab->width : tofill;
	if (!leftalign && (!(tab->flags & FLG_ZERO) ||
	((tab->flags & FLG_ZERO) && tab->precision > 0 && tab->width > tofill)))
		ft_display_gap(tab->width - tofill, ' ');
	if (tab->tmp)
		write(1, &add, 1);
	(!tab->negw) ? (len += ft_display_gap(tab->precision - vallen, '0')) : 0;
	if (tab->flags & FLG_ZERO && tab->precision == 0 && !tab->negw)
		ft_display_gap(tab->width - tofill, '0');
	ft_putnbr_fd(value, 1);
	if (leftalign)
		ft_display_gap(tab->width - tofill, ' ');
	return (len);
}

int				ft_display_d(t_tab *tab)
{
	intmax_t	value;
	int			vallen;
	int			is_negative;

	tab = ft_handle_star(tab);
	value = ft_get_num(tab);
	is_negative = (value < 0) ? 1 : 0;
	value *= (is_negative) ? -1 : 1;
	vallen = ft_numlen(value);
	tab->tmp = (is_negative || (tab->flags & FLG_PLUS && !is_negative)
	|| tab->flags & FLG_SPACE) ? 1 : 0;
	if (value == 0 && tab->precision == -3 && !tab->negp)
	{
		(tab->flags & FLG_PLUS) ? ft_putchar_fd('+', 1) : 0;
		(tab->flags & FLG_SPACE) ? ft_putchar_fd(' ', 1) : 0;
		ft_display_gap(tab->width, ' ');
		return (tab->width);
	}
	return (ft_print_d(tab, value, vallen, is_negative));
}

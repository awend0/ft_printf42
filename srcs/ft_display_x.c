/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:15:49 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

static char			*ft_str_toupper(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (ret);
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

static int			ft_print_x(t_tab *tab, uintmax_t n,
					char *str, int leftalign)
{
	int		tofill;
	int		vallen;
	int		len;

	len = 0;
	if ((vallen = ft_strlen(str)) && tab->flags & FLG_HASH && n
	&& tab->flags & FLG_ZERO && tab->width)
		vallen += 2;
	else if ((vallen = ft_strlen(str)) && tab->flags & FLG_HASH && n)
	{
		tab->width -= 2;
		len += 2;
	}
	tofill = (vallen <= tab->precision && tab->precision > 0)
	? tab->precision : vallen;
	len += (vallen <= tab->width) ? tab->width : vallen;
	(!leftalign) ? (len += ft_display_gap(tab->width - tofill, ' ')) : 0;
	(n && tab->flags & FLG_HASH && tab->type == 'x') ? write(1, "0x", 2) : 0;
	(n && tab->flags & FLG_HASH && tab->type == 'X') ? write(1, "0X", 2) : 0;
	(!tab->negw) ? (len += ft_display_gap(tab->precision - vallen, '0')) : 0;
	if (tab->type == 'X')
		str = ft_str_toupper(str);
	ft_putstr_fd(str, 1);
	(leftalign) ? (len += ft_display_gap(tab->width - tofill, ' ')) : 0;
	return (len);
}

int					ft_display_x(t_tab *tab)
{
	char		*str;
	uintmax_t	n;
	int			leftalign;

	tab = ft_handle_star(tab);
	n = ft_get_num(tab);
	leftalign = (tab->flags & FLG_MINUS) ? 1 : 0;
	if (n == 0 && tab->precision == -3 && !tab->negp)
	{
		return (ft_display_gap(tab->width,
		(tab->flags & FLG_ZERO ? '0' : ' ')));
	}
	if (!(str = ft_itoa_base(n, 16)))
		return (-1);
	if (tab->flags & FLG_ZERO && tab->precision == 0 && !leftalign)
		tab->precision = tab->width;
	return (ft_print_x(tab, n, str, leftalign));
}

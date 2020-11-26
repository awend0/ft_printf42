/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:55:32 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 02:06:29 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

void	ft_debug(t_tab *tab)
{
	printf("Flags:\t[");
	if (tab->flags & FLG_MINUS)
		printf("minus");
	if (tab->flags & FLG_PLUS)
		printf("plus");
	if (tab->flags & FLG_ZERO)
		printf("zero");
	if (tab->flags & FLG_HASH)
		printf("hash");
	if (tab->flags & FLG_SPACE)
		printf("space");
	printf("]\nType:\t[%c]\n", tab->type);
	printf("Width:\t[%d]\n", tab->width);
	printf("Prec:\t[%d]\n", tab->precision);
	printf("Len:\t[%c]\n", tab->len);
}

int		ft_wtp(const char **format)
{
	int	len;

	len = 0;
	while ((**format) && (**format) != '%')
	{
		write(1, (*format), 1);
		(*format)++;
		len++;
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	int		tmp;
	t_tab	*tab;

	if (!(tab = malloc(sizeof(t_tab))))
		return (-1);
	len = 0;
	va_start(tab->args, format);
	while (1)
	{
		tmp = ft_wtp(&format);
		if ((tmp == 0 && *format != '%') || tmp == -1)
			return (tmp == 0 ? len + tmp : -1);
		len += tmp;
		if (*format == '%')
			len += ft_parser(&format, tab);
	}
	free(tab);
	va_end(tab->args);
	return (len);
}

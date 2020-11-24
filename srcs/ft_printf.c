/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:55:32 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/24 17:39:45 by hasvv            ###   ########.fr       */
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

static long long	ft_get_num(t_tab *tab)
{
	long long	num;

	if (tab->len == 'H')
		num = (signed char)(va_arg(tab->args, int));
	else if (tab->len == 'h')
		num = (short)(va_arg(tab->args, int));
	else if (tab->len == 'L')
		num = (long long)(va_arg(tab->args, long long int));
	else if (tab->len == 'l')
		num = (long)(va_arg(tab->args, long int));
	else
		num = (int)(va_arg(tab->args, int));
	num = (long long)num;
	return (num);
}

int		ft_numlen(long long n)
{
	int				res;

	res = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (n < 0 ? res + 1 : res);
}

int		ft_display_d(t_tab *tab)
{
	int				nbrlen;
	long long		value;
	int				len;
	int				i;

	len = 0;
	if (tab->width == -2)
		tab->width = va_arg(tab->args, int);
	if (tab->precision == -2)
		tab->precision = va_arg(tab->args, int);
	value = ft_get_num(tab);
	nbrlen = ft_numlen(value);
	printf("Value: %lld\nLen: %d\n", value, nbrlen);
	ft_debug(tab);
}

int		ft_processor(t_tab *tab)
{
	int		len;


	len = 0;
	if (tab->type == 'd' && (len = ft_display_d(tab)) < 0)
		return (-1);
}

int		ft_parser(const char **format, int len, t_tab *tab)
{
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
	len += ft_processor(tab);
	//ft_debug(tab);
	return (len);
}

int		ft_wtp(const char **format, int len)
{
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
	t_tab	*tab;

	if (!(tab = malloc(sizeof(t_tab))))
		return (-1);
	va_start(tab->args, format);
	printf("\nres: %d\n", ft_parser(&format, 0, tab));
	free(tab);
	va_end(tab->args);
	return (len);
}

int		main(int argc, char *argv[])
{
	int a = -123;
	ft_printf("%*.*d", 10, 10, a);
}

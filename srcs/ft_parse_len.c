/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/23 15:21:55 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

char	ft_parse_len(const char **format, t_tab *tab)
{
	char	len;

	len = 0;
	while (**format && **format != tab->type
			&& **format != 'l' && **format != 'h')
		(*format)++;
	if (**format == 'l' && *(*format + 1) == 'l')
		len = 'L';
	else if (**format == 'h' && *(*format + 1) == 'h')
		len = 'H';
	else if (**format == 'l')
		len = 'l';
	else if (**format == 'h')
		len = 'h';
	return (len);
}

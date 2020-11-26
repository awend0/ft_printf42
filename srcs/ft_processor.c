/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:02:38 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 03:46:28 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int		ft_processor(t_tab *tab)
{
	int		len;

	len = 0;
	if (tab->type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (tab->type == 'd' || tab->type == 'i')
		len = ft_display_d(tab);
	if (tab->type == 'u')
		len = ft_display_u(tab);
	if (tab->type == 'c')
		len = ft_display_c(tab);
	if (tab->type == 's')
		len = ft_display_s(tab);
	if (tab->type == 'p')
		len = ft_display_p(tab);
	if (tab->type == 'x' || tab->type == 'X')
		len = ft_display_x(tab);
	return (len);
}

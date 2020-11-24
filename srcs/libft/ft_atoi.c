/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:28:07 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/01 18:21:54 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char *str)
{
	long	res;
	int		negative;
	int		len;

	negative = 1;
	res = 0;
	len = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
		len++;
		if (len > 10)
			return (negative == -1 ? 0 : -1);
	}
	return (res * negative);
}

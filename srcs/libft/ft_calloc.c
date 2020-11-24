/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:11:13 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/04 18:56:34 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		bytes;
	void	*ret;

	bytes = count * size;
	ret = malloc(bytes);
	if (ret)
		ret = ft_memset(ret, 0, bytes);
	return (ret);
}

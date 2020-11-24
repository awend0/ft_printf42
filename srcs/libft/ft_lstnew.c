/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:58:47 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/03 19:02:12 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list	*node;

	node = ft_memalloc(sizeof(t_list));
	if (!node)
		return (0);
	if (!content)
		node->content = 0;
	else
		node->content = content;
	node->next = 0;
	return (node);
}

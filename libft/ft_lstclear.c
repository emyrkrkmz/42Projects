/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:34:59 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 16:35:12 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		iter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iter;
	}
}

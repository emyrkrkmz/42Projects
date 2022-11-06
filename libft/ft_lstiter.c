/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:35:43 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 16:35:52 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (!lst)
		return ;
	iter = lst;
	while (iter != NULL)
	{
		(*f)(iter->content);
		iter = iter->next;
	}
}

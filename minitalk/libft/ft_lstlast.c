/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:36:09 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 16:36:25 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	iter = lst;
	while (iter != NULL && iter->next != NULL)
	{
		iter = iter->next;
	}
	return (iter);
}

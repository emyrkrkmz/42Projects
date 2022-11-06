/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:15:45 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 18:15:47 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}

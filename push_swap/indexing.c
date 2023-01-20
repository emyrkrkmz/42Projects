/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:06:20 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:20:39 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_before(t_box *a)
{
	int	i;
	int	j;
	int	*tmp;
	int	temp;

	i = -1;
	tmp = malloc(sizeof(int) * a->size);
	while (++i < a->size)
		tmp[i] = a->elements[i];
	i = -1;
	while (++i < a->size)
	{
		j = i - 1;
		while (++j < a->size)
		{
			if (tmp[i] > tmp[j])
			{
				temp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = temp;
			}
		}
	}
	return (tmp);
}

void	indexing(t_box *a)
{
	int	*sort;
	int	i;
	int	j;

	i = -1;
	sort = sort_before(a);
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->elements[i] == sort[j])
			{
				a->elements[i] = j;
				break ;
			}
		}
	}
	free (sort);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_p1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:07:23 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:11:22 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	average_value(t_box *a_box)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	max = __INT_MAX__;
	min = -__INT_MAX__ - 1;
	while (i++ < a_box->size)
	{
		if (a_box->elements[a_box->size - i] > max)
			max = a_box->elements[a_box->size - i];
		if (a_box->elements[a_box->size - i] < min)
			min = a_box->elements[a_box->size - i];
	}
	return ((int)(max + min) / 2);
}

int	max_value_index(t_box *a_box)
{
	int	index;
	int	i;
	int	max;

	i = -1;
	max = -__INT_MAX__ - 1;
	while (++i < a_box->size)
	{
		if (a_box->elements[i] > max)
		{
				max = a_box->elements[i];
				index = i;
		}
	}
	return (index);
}

int	find_suitable_index(t_box *box, int number)
{
	int	diff;
	int	min;
	int	i;
	int	index;

	i = -1;
	min = __INT_MAX__;
	index = -1;
	while (++i < box->size)
	{
		diff = box->elements[box->size - 1 - i] - number;
		if (diff > 0 && diff < min)
		{
			min = diff;
			index = i;
		}
		if (index == -1)
			index = max_value_index(box);
	}
	return (index);
}

void	before_single_rotate(t_box *a, t_box *b, int *i, int *j)
{
	if (*i < (a->size / 2) && *j < (b->size / 2))
	{
		while (*i > 0 && *j > 0)
		{
			multi_rotate(a, b, 0);
			*i -= 1;
			*j -= 1;
		}
	}
	else if (*i >= (a->size / 2) && *j >= (b->size / 2))
	{
		while (*i < a->size && *j < b->size && *i != 0 && *j != 0)
		{
			multi_rev_rotate(a, b, 0);
			*i += 1;
			*j += 1;
		}
	}
}

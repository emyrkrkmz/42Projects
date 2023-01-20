/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:40:30 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 01:44:29 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_pivot(t_swap *s)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = __INT_MAX__;
	max = -__INT_MAX__ - 1;
	while (i++ < s->size)
	{
		if (s->array[s->size - i] > max)
			max = s->array[s->size - i];
		if (s->array[s->size - i] < min)
			min = s->array[s->size - i];
	}
	return ((int)(max + min) / 2);
}

void	send_b(t_swap *a, t_swap *b)
{
	int	pivot;
	int	i;

	i = -1;
	pivot = make_pivot(a);
	if (a->size < 3)
		return ;
	while (++i < a->size)
	{
		if (a->array[a->size - 1] <= pivot)
			push(a, b, 0);
		else
			rotate(a, 0);
	}
	send_b(a, b);
}

int	max_value(t_swap *a)
{
	int	i;
	int	max;
	int	index;

	i = -1;
	max = -__INT_MAX__ - 1;
	while (++i < a->size)
	{
		if (a->array[i] > max)
		{
			max = a->array[i];
			index = i;
		}
	}
	return (index);
}

//b stackteki değerin a'daki en uygun index numarası
int	find_index(t_swap *a, int number)
{
	int	i;
	int	min;
	int	diff;
	int	index;

	i = -1;
	min = __INT_MAX__;
	index = -1;
	while (++i < a->size)
	{
		diff = a->array[a->size - 1 - i] - number;
		if (diff > 0 && diff < min)
		{
			min = diff;
			index = i;
		}
	}
	if (index == -1)
		index = max_value(a);
	return (index);
}

void	sort_path(t_swap *a, t_swap *b, int *i_a, int *i_b)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = __INT_MAX__;
	m = -1;
	while (++m < b->size)
	{
		n = find_index(a, b->array[b->size - 1 - m]);
		if (m < b->size / 2)
			tmp[0] = m;
		else
			tmp[0] = b->size - 1 - m;
		if (n < a->size / 2)
			tmp[1] = n;
		else
			tmp[1] = a->size - 1 - n;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i_b = m;
			*i_a = n;
		}
	}
}

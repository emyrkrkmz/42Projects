/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:47:58 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/20 23:49:27 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_box *a, t_box *b)
{
	int	i_a;
	int	i_b;

	send_b(a, b);
	while (b->size)
	{
		if (a->size <= 1)
			push(b, a, 0);
		sort_path(a, b, &i_a, &i_b);
		send_a(a, b, i_a, i_b);
	}
	get_the_zero(a);
}

void	send_b(t_box *a, t_box *b)
{
	int	average;
	int	i;

	i = -1;
	average = average_value(a);
	if (a->size < 3)
		return ;
	while (++i < a->size)
	{
		if (a->elements[a->size - 1] <= average)
			push(a, b, 0);
		else
			rotate(a, 0);
	}
	send_b(a, b);
}

void	sort_path(t_box *a, t_box *b, int *i_a, int *i_b)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = __INT_MAX__;
	m = -1;
	while (++m < b->size)
	{
		n = find_suitable_index(a, b->elements[b->size - 1 - m]);
		if (m < b->size / 2)
			tmp[0] = m;
		else
			tmp[0] = b->size - 1 - m;
		if (n < a->size / 2)
			tmp[1] = n;
		else
			tmp[1] = b->size - 1 - n;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i_a = n;
			*i_b = m;
		}
	}
}

void	send_a(t_box *a, t_box *b, int i_a, int i_b)
{
	before_single_rotate(a, b, &i_a, &i_b);
	if (i_a < (a->size / 2))
		while (i_a++ < a->size)
			rev_rotate(a, 0);
	else
		while (i_a++ < a->size)
			rev_rotate(a, 0);
	if (i_b < (b->size / 2))
		while (i_b-- > 0)
			rotate(b, 0);
	else
		while (i_b++ < b->size)
			rev_rotate(b, 0);
	push(b, a, 0);
}

void	get_the_zero(t_box *a_box)
{
	int	i;

	i = 0;
	while (a_box->elements[i] != 0)
		i++;
	if (i++ < a_box->size / 2)
		while (i--)
			rev_rotate(a_box, 0);
	else
		while (i++ < a_box->size)
			rotate(a_box, 0);
}

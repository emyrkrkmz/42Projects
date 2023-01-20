/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:24:18 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:26:24 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_arg_sort(t_box *a, t_box *b)
{
	if (a->elements[a->size - 1] == 0)
	{
		if (a->elements[a->size - 2] == 2)
		{
			push(a, b, 0);
			if (a->elements[a->size - 1] > a->elements[a->size - 2])
				swap(a, 0);
			push(b, a, 0);
		}
	}
	else if (a->elements[a->size - 2] == 0)
	{
		if (a->elements[a->size - 1] == 2)
			rotate(a, 0);
		else if (a->elements[a->size - 1] == 1)
			swap(a, 0);
	}
	else if (a->elements[a->size - 3] == 0)
	{
		if (a->elements[a->size - 1] > a->elements[a->size - 2])
			swap(a, 0);
		rev_rotate(a, 0);
	}
}

void	four_arg_sort(t_box *a, t_box *b)
{
	int	i;

	i = 0;
	if (a->size == 4)
	{
		while (a->elements[i] != 3)
			i++;
		if (i == 0)
			rev_rotate(a, 0);
		else
			while (++i < a->size)
				rotate(a, 0);
		push(a, b, 0);
		three_arg_sort(a, b);
		push(b, a, 0);
		rotate(a, 0);
	}
	else
	{
		if (b->elements[b->size - 1] > b->elements[b->size - 2])
			swap(b, 0);
		three_arg_sort(a, b);
		push(b, a, 0);
		rotate(a, 0);
	}
}

void	five_arg_sort_part2(t_box *a, t_box *b, int i)
{
	if (i < 2)
	{
		while (--i >= 0)
		{
			rev_rotate(a, 0);
			if (a->elements[a->size - 1] == 3)
				push(a, b, 0);
		}
	}
	else
	{
		while (i++ < a->size)
		{
			rotate(a, 0);
			if (a->elements[a->size - 1] == 3)
				push(a, b, 0);
		}
	}
}

void	five_arg_sort_part1(t_box *a, t_box *b)
{
	int	i;

	i = 0;
	if (a->elements[a->size - 1] == 3)
		push(a, b, 0);
	while (a->elements[i] != 4)
		i++;
	i++;
	five_arg_sort_part2(a, b, i);
	push(a, b, 0);
	four_arg_sort(a, b);
	push(b, a, 0);
	rotate(a, 0);
}

void	smaller_list(t_box *a, t_box *b)
{
	if (a->size == 2)
	{
		if (a->elements[a->size - 1] > a->elements[a->size - 2])
			swap(a, 0);
	}
	else if (a->size == 3)
		three_arg_sort(a, b);
	else if (a->size == 4)
		four_arg_sort(a, b);
	else if (a->size == 5)
		five_arg_sort_part1(a, b);
}

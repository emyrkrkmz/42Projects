/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:39:31 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 01:44:10 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_the_zero(t_swap *a)
{
	int	i;

	i = 0;
	while (a->array[i] != 0)
		i++;
	if (i++ < a->size / 2)
		while (i--)
			rev_rotate(a, 0);
	else
		while (i++ < a->size)
			rotate(a, 0);
}

void	before_single_rotate(t_swap *a, t_swap *b, int *i, int *j)
{
	if (*i < (a->size / 2) && *j < (b->size / 2))
	{
		while (*i > 0 && *j > 0)
		{
			rotate_together(a, b, 0);
			*i -= 1;
			*j -= 1;
		}
	}
	else if (*i >= (a->size / 2) && *j >= (b->size / 2))
	{
		while (*i < a->size && *j < b->size && *i != 0 && *j != 0)
		{
			rev_rotate_together(a, b, 0);
			*i += 1;
			*j += 1;
		}
	}
}

//en kısa yoldan dönen indexlerin poslarına göre rotateleme başlatılır.
void	send_a(t_swap *a, t_swap *b, int i_a, int i_b)
{
	before_single_rotate(a, b, &i_a, &i_b);
	if (i_a < (a->size / 2))
		while (i_a-- > 0)
			rotate(a, 0);
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

//her şey burada başlıyor
void	sort_list(t_swap *a, t_swap *b)
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

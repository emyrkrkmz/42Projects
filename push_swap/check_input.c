/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:08:02 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:12:33 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chex_double(t_box *a, t_box *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i;
		while (j < a->size - 1)
		{
			if (a->elements[i] == a->elements[j++ + 1])
				error_message(a, b);
		}
		i++;
	}
}

void	check_list(t_box *a, t_box *b)
{
	int	i;
	int	counter;

	i = -1;
	counter = 1;
	while (++i < a->size - 1)
	{
		if (a->elements[i] < a->elements[i + 1])
			counter = 0;
	}
	if (counter == 1)
		makefree(a, b);
}

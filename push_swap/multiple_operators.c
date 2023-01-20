/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:05:37 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:12:53 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multi_swap(t_box *f_box, t_box *s_box, int control)
{
	if (!control)
	{
		swap(f_box, 1);
		swap(s_box, 1);
		ft_printf("ss\n");
	}
}

void	multi_rotate(t_box *f_box, t_box *s_box, int control)
{
	if (!control)
	{
		rotate(f_box, 1);
		rotate(s_box, 1);
		ft_printf("rr\n");
	}
}

void	multi_rev_rotate(t_box *f_box, t_box *s_box, int control)
{
	if (!control)
	{
		rev_rotate(f_box, 1);
		rev_rotate(s_box, 1);
		ft_printf("rrr\n");
	}
}

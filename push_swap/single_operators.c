/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:14:14 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:19:07 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_box *a_stack, int control)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = a_stack->elements[0];
	while (++i < a_stack->size - 1)
		a_stack->elements[i] = a_stack->elements[i + 1];
	a_stack->elements[a_stack->size - 1] = tmp;
	if (!control)
	{
		if (a_stack->stack == 'a')
			ft_printf("rra\n");
		else if (a_stack->stack == 'b')
			ft_printf("rrb\n");
	}
}

void	swap(t_box *a_stack, int control)
{
	int	tmp;

	if (a_stack->size < 2)
		ft_printf("No number to swap");
	tmp = a_stack->elements[a_stack->size - 1];
	a_stack->elements[a_stack->size - 1] = a_stack->elements[a_stack->size - 2];
	a_stack->elements[a_stack->size - 2] = tmp;
	if (!control)
	{
		if (a_stack->stack == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	rotate(t_box *a_stack, int control)
{
	int	i;
	int	tmp;
	int	k;

	i = -1;
	tmp = a_stack->elements[a_stack->size - 1];
	while (++i < a_stack->size - 1)
	{
		k = a_stack->size - i;
		a_stack->elements[k - 1] = a_stack->elements[k - 2];
	}
	a_stack->elements[0] = tmp;
	if (!control)
	{
		if (a_stack->stack == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	push(t_box *stack_one, t_box *stack_two, int control)
{
	int	k;

	if (stack_one->size < 1)
		ft_printf("No number to push");
	k = stack_two->size;
	stack_two->elements[k] = stack_one->elements[k - 1];
	stack_two->size += 1;
	stack_one->size -= 1;
	if (!control)
	{
		if (stack_one->stack == 'a')
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
}

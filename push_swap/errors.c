/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:19:50 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:19:51 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	makefree(t_box *a, t_box *b)
{
	free(a->elements);
	free(b->elements);
	exit(1);
}

void	error_message(t_box *a, t_box *b)
{
	write(2, "Error\n", 6);
	makefree(a, b);
}

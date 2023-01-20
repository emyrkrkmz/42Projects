/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:57:51 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:01:13 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_box	a;
	t_box	b;

	a.stack = 'a';
	b.stack = 'b';
	if (argc >= 2)
		gathering_inputs (argc, argv, &a, &b);
	else
		return (0);
	chex_double(&a, &b);
	check_list(&a, &b);
	indexing(&a);
	if (a.size > 5)
		big_sort(&a, &b);
	else
		smaller_list(&a, &b);
	free(a.elements);
	free(b.elements);
}

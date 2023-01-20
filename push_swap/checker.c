/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:19:43 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:19:44 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list_checker(int *control, t_box *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->elements[i] < a->elements[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}

void	rotate_func(char *s, t_box *a, t_box *b)
{
	if (s[0] == 'r' && s[1] == 'a')
		rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		multi_rev_rotate(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		rev_rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		rev_rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		multi_rev_rotate(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r')
		multi_rotate(a, b, 1);
	else
		error_message(a, b);
}

void	make_pros(t_box *a, t_box *b, char *s)
{
	if (s[0] == 's' && s[1] == 'a')
		swap(a, 1);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b, 1);
	else if (s[0] == 's' && s[1] == 's')
		multi_swap(a, b, 1);
	else if (s[0] == 'r')
		rotate_func(&s[0], a, b);
	else if (s[0] == 'p' && s[1] == 'a')
		push(b, a, 1);
	else if (s[0] == 'p' && s[1] == 'b')
		push(a, b, 1);
	else
		error_message(a, b);
}

void	read_lines(t_box *a, t_box *b)
{
	char	*tmp;
	char	*buff;

	buff = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			return ;
		make_pros(a, b, tmp);
	}
}

int	main(int ac, char **av)
{
	t_box	a;
	t_box	b;
	int		control;

	control = -1;
	a.stack = 'a';
	b.stack = 'b';
	if (ac >= 2)
		gathering_inputs(ac, av, &a, &b);
	else
		return (0);
	chex_double(&a, &b);
	read_lines(&a, &b);
	check_list_checker(&control, &a);
	if (control == 1 && !b.size)
		ft_printf("OK");
	else if (!control || b.size != 0)
		ft_printf("KO");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:09:20 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:10:25 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "Gnl/get_next_line.h"

typedef struct a_box
{
	int	size;
	int	*elements;
	int	stack;
}	t_box;

void	error_message(t_box *a, t_box *b);
int		ft_atoix(char *s, t_box *a, t_box *b);
char	**argv_to_array(int argc, char **argv);
void	gathering_inputs(int argc, char **argv, t_box *a, t_box *b);
int		*sort_before(t_box *a);
void	indexing(t_box *a);
void	chex_double(t_box *a, t_box *b);
void	check_list(t_box *a, t_box *b);
void	big_sort(t_box *a, t_box *b);
void	smaller_list(t_box *a, t_box *b);
void	rev_rotate(t_box *a_stack, int control);
void	swap(t_box *a_stack, int control);
void	rotate(t_box *a_stack, int control);
void	multi_swap(t_box *f_box, t_box *s_box, int control);
void	multi_rotate(t_box *f_box, t_box *s_box, int control);
void	multi_rev_rotate(t_box *f_box, t_box *s_box, int control);
void	three_arg_sort(t_box *a, t_box *b);
void	five_arg_sort_part1(t_box *a, t_box *b);
void	five_arg_sort_part2(t_box *a, t_box *b, int i);
int		average_value(t_box *a_box);
void	send_b(t_box *a, t_box *b);
int		max_value_index(t_box *a_box);
void	sort_path(t_box *a, t_box *b, int *i_a, int *i_b);
int		find_suitable_index(t_box *box, int number);
void	send_a(t_box *a, t_box *b, int i_a, int i_b);
void	get_the_zero(t_box *a_box);
void	check_list_checker(int *control, t_box *a);
void	rotate_func(char *s, t_box *a, t_box *b);
void	make_pros(t_box *a, t_box *b, char *s);
void	read_lines(t_box *a, t_box *b);
void	push(t_box *stack_one, t_box *stack_two, int control);
void	before_single_rotate(t_box *a, t_box *b, int *i_a, int *i_b);
void	makefree(t_box *a, t_box *b);
void	rev_rotate(t_box *a_stack, int control);
void	swap(t_box *a_stack, int control);
void	rotate(t_box *a_stack, int control);
void	push(t_box *stack_one, t_box *stack_two, int control);

#endif

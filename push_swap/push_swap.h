/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:41:43 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 01:41:45 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "Gnl/get_next_line.h"
# include "Libft/libft.h"

typedef struct s_swap
{
	int	*array;
	int	size;
	int	stack;
}	t_swap;

void	free_func(t_swap *a, t_swap *b);
void	error_message(t_swap *a, t_swap *b);
void	more_args(int argc, char **argv, t_swap *a, t_swap *b);
void	check_double(t_swap *a, t_swap *b);
void	check_list(t_swap *a, t_swap *b);
void	sort_path(t_swap *a, t_swap *b, int *i_a, int *i_b);
void	send_b(t_swap *a, t_swap *b);
void	smaller_list(t_swap *a, t_swap *b);
void	sort_list(t_swap *a, t_swap *b);
void	swap(t_swap *data, int control);
void	rotate(t_swap *data, int control);
void	push(t_swap *data, t_swap *data1, int control);
void	rev_rotate(t_swap *data, int control);
void	rotate_together(t_swap *a, t_swap *b, int control);
void	rev_rotate_together(t_swap *a, t_swap *b, int control);
void	swap_together(t_swap *a, t_swap *b, int control);
void	indexing(t_swap *a);
int		ft_atoim(char *str, t_swap *a, t_swap *b);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:40:09 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 01:40:11 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**__arg_array(int argc, char **argv)
{
	char	*tmp;
	char	*string;
	char	**new_string;
	int		index;

	index = 0;
	(void)argc;
	string = ft_strdup("");
	while (argv[++index])
	{
		tmp = string;
		string = ft_strjoin(string, argv[index]);
		free(tmp);
		tmp = string;
		string = ft_strjoin(string, " ");
		free(tmp);
	}
	new_string = ft_split(string, ' ');
	free(string);
	return (new_string);
}

void	more_args(int argc, char **argv, t_swap *a, t_swap *b)
{
	int		i;
	char	**new_string;

	i = 0;
	new_string = __arg_array(argc, argv);
	while (new_string[i])
		i++;
	a->size = i;
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = -1;
	while (new_string[++i])
	{
		a->array[a->size - 1 - i] = ft_atoim(new_string[i], a, b);
		free(new_string[i]);
	}
	free(new_string);
}

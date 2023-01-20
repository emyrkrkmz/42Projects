/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:05:12 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:12:59 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argv_to_array(int argc, char **argv)
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

void	gathering_inputs(int argc, char **argv, t_box *a, t_box *b)
{
	int		i;
	char	**new_string;

	i = 0;
	new_string = argv_to_array(argc, argv);
	while (new_string[i])
		i++;
	a->size = i;
	b->size = 0;
	a->elements = malloc(sizeof(int) * a->size);
	b->elements = malloc(sizeof(int) * a->size);
	i = -1;
	while (new_string[++i])
	{
		a->elements[a->size - 1 - i] = ft_atoix(new_string[i], a, b);
		free(new_string[i]);
	}
	free(new_string);
}

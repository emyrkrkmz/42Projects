/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:01:52 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 17:59:29 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*x;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	x = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(x))
		return (NULL);
	while (i != ft_strlen(s))
	{
		x[i] = (*f)(i, s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}

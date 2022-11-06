/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:32:39 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/02/28 19:32:17 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*dst;
	size_t			i;

	sr = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dst);
}

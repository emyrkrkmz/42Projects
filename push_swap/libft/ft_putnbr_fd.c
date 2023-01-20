/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:33:14 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/01/08 14:33:32 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd ('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd (ln + '0', fd);
	else
	{
		ft_putnbr_fd (ln / 10, fd);
		ft_putnbr_fd (ln % 10, fd);
	}
}

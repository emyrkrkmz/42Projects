/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:34:32 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/10/02 17:33:45 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include <unistd.h>

int	ft_multiply(int i)
{
	int	c;

	c = 1;
	while (i > 0)
	{
		c *= 2;
		i--;
	}
	return (c);
}

void	convert_binary_to_ascii(int c)
{
	static int	character = 0;
	static int	i = 7;

	if (c == 1)
		character += ft_multiply(i);
	if (i == 0)
	{
		write(1, &character, 1);
		i = 8;
		character = 0;
	}
	i--;
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		convert_binary_to_ascii(1);
	else if (sig == SIGUSR2)
		convert_binary_to_ascii(0);
}

int	main(void)
{
	write(1, "Server Pid: ", 13);
	write(1, ft_itoa(getpid()), 13);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

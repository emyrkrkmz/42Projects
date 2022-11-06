/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:32:41 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/10/02 17:07:48 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include <unistd.h>

void	send_character_bits(int c, int pid)
{
	unsigned char	message_char;
	int				i;

	message_char = c;
	i = 128;
	while (i >= 1)
	{
		if (message_char / i)
		{
			message_char -= i;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i /= 2;
	}
}

void	send_message(char *message, int pid)
{
	while (*message)
	{
		send_character_bits(*message, pid);
		message++;
	}
	send_character_bits('\n', pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_message(message, pid);
	}
}

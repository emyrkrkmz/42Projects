/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:01:47 by ekorkmaz          #+#    #+#             */
/*   Updated: 2023/01/21 00:01:50 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(char *buff, int fd, char **str)
{
	int		i;
	char	*temp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!*str)
				*str = ft_substr(buff, 0, i);
			else
			{
				temp = *str;
				*str = ft_strjoin(*str, buff);
				free(temp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

char	*ft_process(char **str)
{
	char	*line;
	char	*temp;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		if (!ft_strlen(*str))
		{
			free(*str);
			*str = 0;
			return (NULL);
		}
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (line);
	}
	line = ft_substr(*str, 0, ft_strlen(*str) \
			- ft_strlen(ft_strchr(*str, '\n')) + 1);
	temp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1 \
			, ft_strlen(ft_strchr(*str, '\n')) - 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (NULL);
	}
	ft_read(buff, fd, &str);
	return (ft_process(&str));
}
/*
#include <stdio.h>
#include <fcntl.h>
int    main()
{
    int  fd1 = open("test1.txt", O_CREAT | O_RDWR, 0777);
    write(fd1, "11111\naaaaaa\n\n\ndddddd\n", 22);
    close(fd1);
    fd1 = open("test1.txt", O_CREAT | O_RDWR, 0777);
    
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd1));
    close(fd1);
   
}*/

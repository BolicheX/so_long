/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:00:12 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/12 17:12:20 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_buff(int fd, char *save, char *buff)
{
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
		{
			free(save);
			return (NULL);
		}
		buff[bytes] = '\0';
		if (!save)
			save = (char *)ft_calloc(sizeof(char), 1);
		save = ft_strjoin_free1(save, buff);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (save);
}

char	*cut_line(char **save)
{
	size_t	cut;
	char	*line;
	char	*tmp;

	cut = 0;
	while ((*save)[cut] && (*save)[cut] != '\n')
		cut++;
	line = ft_substr(*save, 0, cut + 1);
	tmp = *save;
	*save = ft_substr(tmp, cut + 1, ft_strlen(*save) - cut);
	free(tmp);
	if (**save == '\0')
	{
		free(*save);
		*save = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	save = add_buff(fd, save, buff);
	free(buff);
	buff = 0;
	if (!save)
		return (NULL);
	line = cut_line(&save);
	if (!line)
		return (NULL);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("hello.txt", O_RDWR);

	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
	return (0);
}*/

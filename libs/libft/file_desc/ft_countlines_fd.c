/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlines_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:49:32 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/21 17:27:04 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_countlines_fd(int fd)
{
	int		bytes;
	int		lines;
	int		i;
	char	buff[BUFFER_SIZE];

	bytes = 1;
	lines = 0;
	while (bytes > 0)
	{
		i = 0;
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		while (i < bytes)
		{
			if (buff[i] == '\n')
				lines++;
			i++;
		}
	}
	return (lines + 1);
}

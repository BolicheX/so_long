/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:57:03 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/12 17:12:15 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*ft_strjoin_free1(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	free(s1);
	s1 = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)(c))
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	else if (len > (slen - start))
		len = slen - start;
	str = (char *) malloc ((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	j = start;
	while (s[i] && len--)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

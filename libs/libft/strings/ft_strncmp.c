/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:39:13 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/31 12:43:15 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*
int	main(void)
{
	char	*a;
	char	*b;
	int     c;

	a = "ABCDZ";
	b = "ACCDZ";
	c = 2;
	printf("Mi Funcion: %d\n", ft_strncmp(a, b, c));
	printf("Original: %d\n", strncmp(a, b, c));
	return (0);
}*/

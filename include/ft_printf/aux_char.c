/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:47 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/12 20:38:06 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	char	a;

	a = (char)c;
	return (write(1, &a, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_printf("%s", "(null)");
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_point(unsigned long n)
{
	char		*hex;
	static int	i;

	i = 0;
	hex = "0123456789abcdef";
	if (n == 0)
	{
		ft_printf("%s", "(nil)");
		return (5);
	}
	if (n >= 16)
		print_point(n / 16);
	if (i == 0)
		i += write(1, "0x", 2);
	i += write (1, &hex[n % 16], 1);
	return (i);
}

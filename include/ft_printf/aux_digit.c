/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:18:02 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/20 15:14:23 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_numbr(long n, int recurs)
{
	static int	i;
	char		a;

	if (!recurs)
		i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		print_numbr(n / 10, 1);
	a = (n % 10) + '0';
	i += write(1, &a, 1);
	return (i);
}

int	print_numbr_unsign(unsigned long n, int recurs)
{
	static int	i;
	char		a;

	if (!recurs)
		i = 0;
	if (n > 9)
		print_numbr_unsign(n / 10, 1);
	a = (n % 10) + '0';
	i += write(1, &a, 1);
	return (i);
}

int	print_numbr_hex(unsigned long n, int recurs)
{
	static int	i;
	char		*h;

	h = ("0123456789abcdef");
	if (!recurs)
		i = 0;
	if (n > 15)
		print_numbr_hex(n / 16, 1);
	i += write(1, &h[n % 16], 1);
	return (i);
}

int	print_numbr_hexu(unsigned long n, int recurs)
{
	static int	i;
	char		*h;

	h = ("0123456789ABCDEF");
	if (!recurs)
		i = 0;
	if (n > 15)
		print_numbr_hexu(n / 16, 1);
	i += write(1, &h[n % 16], 1);
	return (i);
}

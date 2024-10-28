/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:13:45 by jose-jim          #+#    #+#             */
/*   Updated: 2024/08/20 21:33:13 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char conv, va_list arg)
{
	int	i;

	i = 0;
	if (conv == 'c')
		i += print_char(va_arg(arg, int));
	else if (conv == 's')
		i += print_str(va_arg(arg, char *));
	else if (conv == 'p')
		i += print_point((unsigned long)va_arg(arg, void *));
	else if (conv == 'd' || conv == 'i')
		i += print_numbr((long)va_arg(arg, int), 0);
	else if (conv == 'u')
		i += print_numbr_unsign((unsigned long)va_arg(arg, unsigned int), 0);
	else if (conv == 'x')
		i += print_numbr_hex((unsigned long)va_arg(arg, unsigned int), 0);
	else if (conv == 'X')
		i += print_numbr_hexu((unsigned long)va_arg(arg, unsigned int), 0);
	else if (conv == '%')
		i += write(1, "%", 1);
	else
		return (-1);
	return (i);
}

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s != '%')
			i += write(1, s, 1);
		else
		{
			j = format(*(++s), arg);
			if (j < 0)
				return (-1);
			else
				i = i + j;
		}
		s++;
	}
	va_end(arg);
	return (i);
}

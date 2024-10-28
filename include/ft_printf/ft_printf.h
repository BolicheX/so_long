/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:50:07 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/20 15:06:45 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_point(unsigned long n);
int	print_numbr(long n, int recurs);
int	print_numbr_unsign(unsigned long n, int recurs);
int	print_numbr_hex(unsigned long n, int recurs);
int	print_numbr_hexu(unsigned long n, int recurs);

int	format(char conv, va_list arg);
int	ft_printf(char const *s, ...);

#endif
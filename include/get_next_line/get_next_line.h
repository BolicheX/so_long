/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:07:52 by jose-jim          #+#    #+#             */
/*   Updated: 2024/06/12 17:12:08 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char				*add_buff(int fd, char *save, char *buff);
char				*cut_line(char **save);
char				*get_next_line(int fd);
/*	---		utils	---	*/
size_t				ft_strlen(const char *s);
char				*ft_strjoin_free1(char *s1, char const *s2);
char				*ft_strchr(const char *s, int character);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(const char *s, unsigned int start, size_t len);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:11:42 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 17:17:35 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

// ---------- PRINTF -------------
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(long n, int base);
int		ft_putupper(unsigned int n, int base);
int		ft_putpointer(unsigned long n, int base);
int		ft_printf(const char *format, ...);

// ----------- GET_NEXT_LINE -----------
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:58:47 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/15 18:01:30 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (0);
}

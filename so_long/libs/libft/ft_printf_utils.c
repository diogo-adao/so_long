/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:53:32 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/27 15:45:16 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ********** %c **********
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

// ********** %s **********
int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}

// ********** %d / %i / %u / %x **********
int	ft_putnbr(long n, int base)
{
	int		count;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = n * -1;
	}
	if (n < base)
		count += ft_putchar(hexa[n]);
	else
	{
		count += ft_putnbr(n / base, base);
		count += ft_putnbr(n % base, base);
	}
	return (count);
}

// ********** %X **********
int	ft_putupper(unsigned int n, int base)
{
	int		count;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += ft_putchar(hexa[n]);
	else
	{
		count += ft_putupper(n / base, base);
		count += ft_putupper(n % base, base);
	}
	return (count);
}

// ********** %p **********
int	ft_putpointer(unsigned long n, int base)
{
	int		count;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	if (n < 16)
		count += ft_putchar(hexa[n]);
	else
	{
		count += ft_putnbr(n / base, base);
		count += ft_putnbr(n % base, base);
	}
	return (count);
}

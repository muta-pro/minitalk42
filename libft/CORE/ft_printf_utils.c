/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:33:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/06 16:21:26 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	chars_print;

	if (!s)
		return (write(1, "(null)", 6));
	chars_print = 0;
	while (s[chars_print])
	{
		if (write (1, &s[chars_print], 1) == -1)
			return (-1);
		chars_print++;
	}
	return (chars_print);
}

int	ft_putnbr(int n)
{
	int	chars_print;

	chars_print = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		chars_print += ft_putchar('-');
		if (chars_print == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		chars_print += ft_putnbr(n / 10);
		if (chars_print == -1)
			return (-1);
		chars_print += ft_putchar((n % 10) + '0');
	}
	else
		chars_print += ft_putchar(n + '0');
	return (chars_print);
}

int	ft_putuns(unsigned int n)
{
	int	chars_print;

	chars_print = 0;
	if (n > 9)
	{
		chars_print += ft_putuns(n / 10);
		chars_print += ft_putuns(n % 10);
	}
	else
		chars_print += ft_putchar(n + '0');
	return (chars_print);
}

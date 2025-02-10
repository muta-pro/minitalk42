/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:25:19 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/02 18:05:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n, char spec)
{
	if (spec == 'x')
		return (ft_base16(n, "0123456789abcdef"));
	return (ft_base16(n, "0123456789ABCDEF"));
}

int	ft_putptr(void *p)
{
	int				chars_print;
	unsigned long	a;

	chars_print = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	a = (unsigned long)p;
	chars_print += write(1, "0x", 2);
	chars_print += ft_base16(a, "0123456789abcdef");
	return (chars_print);
}

int	ft_base16(unsigned long n, char *base)
{
	int	chars_print;

	chars_print = 0;
	if (n > 15)
	{
		chars_print += ft_base16(n / 16, base);
		chars_print += ft_base16(n % 16, base);
	}
	else
		chars_print += ft_putchar(base[n]);
	return (chars_print);
}

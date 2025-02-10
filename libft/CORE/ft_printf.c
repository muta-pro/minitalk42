/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:32:53 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/06 16:21:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *fs, ...)
{
	va_list	args;
	int		chars_print;

	if (!fs)
		return (-1);
	va_start(args, fs);
	chars_print = 0;
	while (*fs)
	{
		if (*fs == '%')
		{
			fs++;
			if (*fs)
				chars_print += handle_placeholder(*fs, args);
			else
				return (-1);
		}
		else if (ft_putchar(*fs) == -1)
			return (-1);
		else
			chars_print++;
		fs++;
	}
	va_end(args);
	return (chars_print);
}

int	handle_placeholder(char spec, va_list args)
{
	int	chars_print;

	chars_print = 0;
	if (spec == 'c')
		chars_print += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		chars_print += ft_putstr(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		chars_print += ft_putnbr(va_arg(args, int));
	else if (spec == 'p')
		chars_print += ft_putptr(va_arg(args, void *));
	else if (spec == 'u')
		chars_print += ft_putuns(va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		chars_print += ft_puthex(va_arg(args, unsigned int), spec);
	else if (spec == '%')
		chars_print = ft_putchar('%');
	else
	{
		chars_print += ft_putchar('%');
		chars_print += ft_putchar(spec);
	}
	return (chars_print);
}

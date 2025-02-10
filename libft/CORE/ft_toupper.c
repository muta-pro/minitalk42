/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:06:12 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/31 17:07:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * ft_toupper: Converts a lowercase letter to uppercase.
 * Params: int c (character to convert)
 * Return: int - uppercase character or original if not lowercase
 */
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}

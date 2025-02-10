/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:55:05 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/31 14:55:48 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * ft_tolower: Converts an uppercase letter to lowercase.
 * Params: int c (character to convert)
 * Return: int - lowercase character or original if not uppercase
 */
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c += 32;
		return (c);
	}
	else
		return (c);
}

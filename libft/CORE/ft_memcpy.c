/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:49:41 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/31 14:53:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*s;

	if (!dest && ! src)
		return (NULL);
	dst = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n-- > 0)
	{
		*dst++ = *s++;
	}
	return (dest);
}

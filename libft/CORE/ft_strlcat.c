/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:43:45 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/30 18:45:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*concatenates two strings, ensuring that it doesn’t exceed 
the destination buffer size.It ensures the destination 
string (dst) is null-terminated.
It does not exceed the buffer size size provided by the caller.
It returns the total length of the string it tried to create,
 even if it gets truncated due to insufficient space.*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size -1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

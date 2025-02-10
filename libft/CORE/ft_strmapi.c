/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:11:23 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/30 18:44:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dst[i] = (f)(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

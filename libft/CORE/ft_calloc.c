/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:19:09 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/31 13:53:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//mem alloc for array of elem. block of mem for multiple elem zero-initialized.
//ARG num elem to allocate and their size, multiplyed internally
//safer than malloc cuz it pervents overflows
//each alloc byte is set to 0, zeroed array
//returns void * to alloc mem or NULL if alloc fails, need for casting
//useful for consistent behaviour of data struct, matrices, dynamic alloc arrok 
//dynamic arrays:gets arr of NULLed pointers - slots for insertions logic
//linked list: nodes alloc - next pointers start NULL - already initialized
//matric initialization to 0: no edges between nodes
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:14:48 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 15:58:41 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*start;

	start = (t_list *)malloc(sizeof(t_list));
	if (start == NULL)
		return (NULL);
	start->content = content;
	start->next = NULL;
	return (start);
}

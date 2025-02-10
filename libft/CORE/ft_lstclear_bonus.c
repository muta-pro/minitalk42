/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcelar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:54:23 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 16:13:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store;

	while (*lst != NULL)
	{
		store = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = store;
	}
	*lst = NULL;
}

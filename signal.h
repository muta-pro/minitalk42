/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:05:54 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/03 18:29:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define NUM_BITS 8

typedef struct receiver_state_t
{
	char	curr_char;
	int		bit;
}	t_received;
extern t_received	g_received;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:53:23 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/03 18:22:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "signal.h"
/*
** sender.c - Signal-based character transmission
** Supports: ASCII characters (0-127)
** Note: Unicode/special characters may not transmit correctly
** Usage: ./sender <PID> <string>
*/
volatile sig_atomic_t	g_sig_received = 0;

void	handle_acknowledgment(int signal)
{
	(void)signal;
	g_sig_received = 1;
}

void	handler_registration(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_acknowledgment;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "error: failed to register handler\n", 34);
		exit(1);
	}
}

void	send_bit(pid_t pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR2;
	else
		signal = SIGUSR1;
	if (kill(pid, signal) == -1)
	{
		write(2, "kill error", 11);
		exit(1);
	}
	while (!g_sig_received)
		pause();
	g_sig_received = 0;
}

void	send_string(pid_t pid, const char *str)
{
	int				i;
	int				j;
	int				bit;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		j = 0;
		while (j < NUM_BITS)
		{
			bit = (c >> j) & 1;
			send_bit(pid, bit);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < NUM_BITS)
	{
		send_bit(pid, 0);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(2, "Usage ./sender <PID> <str>\n", 27);
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "invalid PID\n", 12);
		return (1);
	}
	handler_registration();
	send_string(pid, argv[2]);
	return (0);
}

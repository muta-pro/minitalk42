/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/03 18:25:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "signal.h"

t_received	g_received = {0, 0};

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
		g_received.curr_char |= (1 << g_received.bit);
	else
		g_received.curr_char &= ~(1 << g_received.bit);
	g_received.bit++;
	if (g_received.bit == NUM_BITS)
	{
		if (g_received.curr_char == '\0')
		{
			write(1, "\ngot the string from PID: ", 26);
			ft_printf("%d\n", info->si_pid);
		}
		else
		{
			write(1, &g_received.curr_char, 1);
		}
		g_received.curr_char = 0;
		g_received.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			sa_mask;
	pid_t				pid;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "failed handler", 15);
		return (1);
	}
	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}

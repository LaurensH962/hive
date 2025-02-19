/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:41:22 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/19 15:09:37 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char		g_received_msg[2097152];

static int	end_of_message(pid_t client_pid, int char_index)
{
	ft_printf("Server received message:\n%s\n", g_received_msg);
	ft_bzero(g_received_msg, 2097152);
	kill(client_pid, SIGUSR1);
	return (char_index = 0);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit_count = 0;
	static char		current_char = 0;
	static int		char_index = 0;
	static pid_t	client_pid;

	(void)context;
	current_char <<= 1;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		current_char |= 1;
	if (sig == SIGUSR1 || sig == SIGUSR2)
		kill(client_pid, SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			char_index = end_of_message(client_pid, char_index);
		else
			g_received_msg[char_index++] = current_char;
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server running... PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_bzero(g_received_msg, 2097152);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:45:00 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/19 12:08:43 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_message_received = 0;

static void	handle_server_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static pid_t	server_pid;

	(void)context;
	if (info->si_pid != 0)
		server_pid = info->si_pid;
	if (sig == SIGUSR2)
	{
		bit++;
		g_message_received = 1;
	}
	else if (sig == SIGUSR1)
	{
		g_message_received = 1;
		usleep(400);
		ft_printf("Server (PID: %d) received %d bytes", server_pid, bit / 8);
		ft_printf("(%d bits) and printed the full message.\n", bit);
		exit(EXIT_SUCCESS);
	}
}

static void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c & (1 << i));
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_message_received == 0)
			pause();
		g_message_received = 0;
		i--;
	}
}

static void	send_message(int pid, const char *message)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(message))
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
	while (g_message_received == 0)
		pause();
}

int	is_valid_pid(const char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	if (!pid_str[i])
		return (0);
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
			return (0);
		i++;
	}
	pid = atoi(pid_str);
	if (pid <= 0)
		return (0);
	if (kill(pid, 0) == -1)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	char				*message;
	struct sigaction	sa;

	if (argc < 3 || !is_valid_pid(argv[1]))
	{
		ft_printf("Invalid arguments or invalid PID.\n");
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_server_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_pid = atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}

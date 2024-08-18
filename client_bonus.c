/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:49:54 by kaokazak          #+#    #+#             */
/*   Updated: 2024/08/18 15:33:48 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile int	g_flag = TRUE;

static void	error_message(int err)
{
	if (err == ERROR_PID)
		ft_putstr_fd("Error: invalid PID\n", 2);
	if (err == ERROR_SIGNAL)
		ft_putstr_fd("Error: failed to set signal handler\n", 2);
	if (err == ERROR_KILL)
		ft_putstr_fd("Error: failed to send signal\n", 2);
	if (err == ERROR_ARG)
		ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 2);
	exit(0);
}

static void	kill_to_server(pid_t server_pid, char c, int bit)
{
	if (((c >> (7 - bit)) & 1) == 1)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			error_message(ERROR_KILL);
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
			error_message(ERROR_KILL);
	}
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_flag = TRUE;
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("---client complete---\n", 2);
		exit(0);
	}
}

static void	ft_send_message(pid_t pid, char *message)
{
	static int	bit = 0;

	while (*message != '\0')
	{
		if (bit == 8)
		{
			message++;
			bit = 0;
		}
		if (g_flag == TRUE)
		{
			g_flag = FALSE;
			usleep(30);
			kill_to_server(pid, *message, bit++);
		}
	}
	while (*message == '\0' && bit < 8)
	{
		if (g_flag == TRUE)
		{
			g_flag = FALSE;
			usleep(30);
			kill_to_server(pid, *message, bit++);
		}
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		error_message(ERROR_ARG);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	if (signal(SIGUSR1, signal_handler) == SIG_ERR || signal(SIGUSR2,
			signal_handler) == SIG_ERR)
	{
		error_message(ERROR_SIGNAL);
		return (1);
	}
	ft_send_message(server_pid, message);
	pause();
	return (0);
}

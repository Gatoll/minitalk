#include "minitalk.h"

void error_message(int err)
{
    if (err == ERROR_PID)
        ft_putstr_fd("Error: invalid PID\n", 2);
    if (err == ERROR_SIGACTION)
        ft_putstr_fd("Error: failed to set signal handler\n", 2);
    if (err == ERROR_KILL)
        ft_putstr_fd("Error: failed to send signal\n", 2);
    if (err == ERROR_ARG)
        ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 2);
}

void kill_to_server(pid_t server_pid, int sig)
{
    if (sig == SIGUSR1)
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

void	ft_send_bit(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(500);
		if (((c >> bit) & 1) == 1)
            kill_to_server(pid, SIGUSR1);
		else
            kill_to_server(pid, SIGUSR2);
		bit++;
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	while (*message != '\0')
	{
		ft_send_bit(pid, *message);
		message++;
	}
	ft_send_bit(pid, '\0');
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
	ft_send_message(server_pid, message);
	return (0);
}

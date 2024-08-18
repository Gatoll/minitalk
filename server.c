#include "minitalk.h"

void error_message(int err)
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

void kill_to_client(pid_t client_pid, int sig)
{
    if (sig == SIGUSR1)
    {
        if (kill(client_pid, SIGUSR1) == -1)
            error_message(ERROR_KILL);
    }
    else
    {
        if (kill(client_pid, SIGUSR2) == -1)
            error_message(ERROR_KILL);
    }
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;
    (void)context;
	
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
        {
            write(1, "\n", 1);
            kill_to_client(info->si_pid, SIGUSR2);
            ft_putstr_fd("---server complete---\n", 1);
        }
		else
        {
			write(1, &c, 1);
            kill_to_client(info->si_pid, SIGUSR1);
        }
        c = 0;
		bit = 0;
	}
    else
        kill_to_client(info->si_pid, SIGUSR1);
}

int check_pid(pid_t pid)
{
    if (pid < 1 || pid > INT_MAX)
    {
        error_message(ERROR_PID);
        return (-1);
    }
    return (0);
}

int	main(void)
{
	pid_t	pid;
    struct sigaction sa;

	pid = getpid();
    if (check_pid(pid) == -1)
    {
        error_message(ERROR_PID);
        return (1);
    }
	ft_printf("PID : %d\n", pid);
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		error_message(ERROR_SIGNAL);
		return (1);
	}
	while (1)
		pause();
	return (0);
}

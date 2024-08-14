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

void	ft_handler(int sig)
{
	static int	bit;
	static char	c;
	
	if (sig == SIGUSR1)
		c |= (1 << bit);
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	bit++;
	if (bit > 7)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, ft_handler) == SIG_ERR || signal(SIGUSR2, ft_handler) == SIG_ERR)
	{
		error_message(ERROR_SIGACTION);
		return (1);
	}
	while (1)
		pause();
	return (0);
}

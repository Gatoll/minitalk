#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"

#include <aio.h> //pid_t
#include <signal.h>

#define ERROR_PID 1
#define ERROR_SIGACTION 2
#define ERROR_KILL 3
#define ERROR_ARG 4

typedef struct s_client_data {
    pid_t server_pid;
    char *message;
} t_client_data;

#endif
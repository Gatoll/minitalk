/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:50:13 by kaokazak          #+#    #+#             */
/*   Updated: 2024/08/18 14:51:33 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <aio.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define ERROR_PID 1
# define ERROR_SIGNAL 2
# define ERROR_KILL 3
# define ERROR_ARG 4

#endif
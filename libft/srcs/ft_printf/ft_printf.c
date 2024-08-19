/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:29:59 by kaokazak          #+#    #+#             */
/*   Updated: 2024/08/19 05:31:44 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_len(va_arg(args, const char *)));
	else if (format == 'p')
		return (ft_putptr_len(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr_len(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex_len(format, va_arg(args, unsigned int)));
	else
		return (ft_putchar_len(format));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	va_start(args, str);
	print_len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '\0')
			break ;
		else if (*str == '%')
		{
			str++;
			print_len += ft_format(*str, args);
		}
		else
			print_len += ft_putchar_len((int)*str);
		str++;
	}
	va_end(args);
	return (print_len);
}

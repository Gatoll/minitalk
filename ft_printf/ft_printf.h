/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:29:56 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/30 13:35:27 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int	ft_printf(const char *str, ...);
int	ft_putchar_len(int c);
int	ft_putstr_len(const char *str);
int	ft_putptr_len(void *ptr);
int	ft_putnbr_len(int num);
int	ft_putunbr_len(unsigned int num);
int	ft_puthex_len(char format, unsigned int num);

#endif

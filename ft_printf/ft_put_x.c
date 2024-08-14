/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:16 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/29 19:09:24 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_rec_puthex_len(char format, unsigned int num)
{
	if (num >= 16)
		ft_rec_puthex_len(format, num / 16);
	if (format == 'x')
		ft_putchar_len(HEX_LOWER[num % 16]);
	else if (format == 'X')
		ft_putchar_len(HEX_UPPER[num % 16]);
}

int	ft_puthex_len(char format, unsigned int num)
{
	int	len;

	ft_rec_puthex_len(format, num);
	len = 0;
	while (num >= 16)
	{
		len++;
		num /= 16;
	}
	len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_diux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:04 by kaokazak          #+#    #+#             */
/*   Updated: 2024/08/19 18:18:42 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int num)
{
	long int	nb;
	int len;
	char c;
	
	nb = (long)num;
	len = 0;
	
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		len++;
	}
	if (nb > 9)
		len += ft_putnbr_len(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	len++;

	return (len);
}

int	ft_putunbr_len(unsigned int num)
{
	int	len;
	char c;

	len = 0;
	if (num > 9)
		len += ft_putunbr_len(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_puthex_len(char format, unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex_len(format, num / 16);
	if (format == 'x')
		len += ft_putchar_len(HEX_LOWER[num % 16]);
	else if (format == 'X')
		len += ft_putchar_len(HEX_UPPER[num % 16]);
	return (len);
}

static void	ft_rec_putptr_len(uintptr_t adr)
{
	if (adr >= 16)
		ft_rec_putptr_len(adr / 16);
	ft_putchar_len(HEX_LOWER[adr % 16]);
}

int	ft_putptr_len(void *ptr)
{
	uintptr_t	adr;
	int			len;

	adr = (uintptr_t)ptr;
	len = 0;
	len += ft_putstr_len("0x");
	ft_rec_putptr_len(adr);
	while (adr >= 16)
	{
		len++;
		adr /= 16;
	}
	len++;
	return (len);
}

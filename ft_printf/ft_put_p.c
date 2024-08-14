/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:07 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/29 19:08:16 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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

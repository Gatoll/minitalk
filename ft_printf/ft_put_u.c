/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:09 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/29 19:09:12 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_rec_putunbr_len(unsigned int num)
{
	if (num > 9)
		ft_rec_putunbr_len(num / 10);
	ft_putchar_len((num % 10) + '0');
}

int	ft_putunbr_len(unsigned int num)
{
	int	len;

	ft_rec_putunbr_len(num);
	len = 1;
	while (num > 9)
	{
		len++;
		num /= 10;
	}
	return (len);
}

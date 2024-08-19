/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:41:24 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/21 22:25:19 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_putnbr_fd(long int nb, int fd)
{
	char	cn;

	if (nb > 9)
		ft_rec_putnbr_fd(nb / 10, fd);
	cn = nb % 10 + '0';
	ft_putchar_fd(cn, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	ft_rec_putnbr_fd(nb, fd);
}

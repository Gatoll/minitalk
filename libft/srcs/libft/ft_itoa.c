/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:34:13 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/22 21:55:56 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	long int	nb;
	int			len;

	nb = (long int)n;
	len = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	if (nb > 0)
	{
		len++;
		while (nb / 10)
		{
			nb /= 10;
			len++;
		}
	}
	return (len);
}

static char	*ft_sub_itoa(int n, char *res, int len)
{
	long int	nb;

	nb = (long int)n;
	res[len--] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = ft_intlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_sub_itoa(n, res, len);
	return (res);
}

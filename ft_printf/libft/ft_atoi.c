/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:32:03 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/21 19:13:37 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_longover(int sign, unsigned long res, unsigned long num)
{
	if (res > (unsigned long)LONG_MAX / 10)
		return (TRUE);
	if (res == (unsigned long)LONG_MAX / 10)
	{
		if (sign == 1 && num > (unsigned long)LONG_MAX % 10)
			return (TRUE);
		else if (sign == -1 && num > (unsigned long)LONG_MIN % 10)
			return (TRUE);
	}
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_longover(sign, res, (*str - '0')))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			return ((int)LONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * res));
}

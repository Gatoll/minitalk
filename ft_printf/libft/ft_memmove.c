/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:40 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/22 11:34:31 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	if (!dst && !src)
		return (NULL);
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	if (dst <= src)
	{
		while (len-- > 0)
			*(u_dst++) = *(u_src++);
	}
	else
	{
		u_dst += len - 1;
		u_src += len - 1;
		while (len-- > 0)
			*(u_dst--) = *(u_src--);
	}
	return (dst);
}

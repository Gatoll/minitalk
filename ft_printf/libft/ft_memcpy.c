/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:31 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/22 11:35:24 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;
	size_t				i;

	if (!dst && !src)
		return (dst);
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	return (dst);
}

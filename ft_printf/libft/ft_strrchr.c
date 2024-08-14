/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:43:27 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/23 12:10:24 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*adr;
	char	cc;

	adr = NULL;
	cc = (char)c;
	while (*s != '\0')
	{
		if (*s == cc)
			adr = (char *)s;
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (adr);
}

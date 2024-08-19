/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:43:27 by kaokazak          #+#    #+#             */
/*   Updated: 2024/05/07 20:31:53 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		end;

	cc = (char)c;
	end = ft_strlen(s);
	while (end >= 0)
	{
		if (s[end] == cc)
			return ((char *)&s[end]);
		end--;
	}
	return (NULL);
}

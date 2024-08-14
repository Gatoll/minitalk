/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:43:47 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/23 12:07:44 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if ((size_t)start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		res[i] = s[(size_t)start + i];
		i++;
	}
	return (res);
}

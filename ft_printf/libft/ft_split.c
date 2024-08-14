/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:41:46 by kaokazak          #+#    #+#             */
/*   Updated: 2024/04/23 12:15:32 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static char	*ft_copy_word(const char *str, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !ft_issep(str[len], c))
		len++;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_issep(s[i], c))
		{
			count++;
			while (s[i] != '\0' && !ft_issep(s[i], c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (!ft_issep(*s, c))
		{
			res[i] = ft_copy_word(s, c);
			if (!res[i])
				return (ft_free(res, i));
			while (*s != '\0' && !ft_issep(*s, c))
				s++;
			i++;
		}
		else
			s++;
	}
	return (res);
}

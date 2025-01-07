/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:04:50 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/17 13:50:55 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_tokens(const char *s, char c)
{
	size_t	count;
	int		in_token;

	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	count = 0;
	in_token = 0;
	while (*s)
	{
		if (*s != c && !in_token)
		{
			in_token = 1;
			count++;
		}
		else if (*s == c)
			in_token = 0;
		s++;
	}
	return (count);
}

static char	**ft_free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static size_t	ft_aux(char const *s, char c)
{
	if (c == '\0')
		return (ft_strlen(s));
	if (!ft_strchr(s, c))
		return (ft_strlen(s));
	else
		return (ft_strchr(s, c) - s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	len = ft_count_tokens(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_aux(s, c);
			result[i] = ft_substr(s, 0, len);
			if (!result[i])
				return (ft_free_all(result));
			i++;
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}

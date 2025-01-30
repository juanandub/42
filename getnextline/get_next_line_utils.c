/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:40:10 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/27 13:44:29 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != 0)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	int		i;

	len = ft_strlen(s) + 1;
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	if (!str && !s)
		return (0);
	i = 0;
	while (len--)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

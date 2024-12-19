/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:10:22 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/11 12:35:14 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t count);

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(str, s, len + 1);
	return (str);
}

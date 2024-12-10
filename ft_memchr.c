/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:54:46 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:02 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*aux;

	aux = (const char *)s;
	while (*aux && n--)
	{
		if (*aux == (char) c)
		{
			return ((void *) aux);
		}
		aux++;
	}
	return (0);
}

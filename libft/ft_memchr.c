/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:54:46 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/14 09:41:14 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*aux;

	aux = (const unsigned char *)s;
	while (n--)
	{
		if (*aux == (unsigned char) c)
		{
			return ((void *) aux);
		}
		aux++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:15:33 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/06 13:48:58 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);


size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	len;
	
	len = 0;
	while (dst[len] != 0)
		len++;
	while (len < size - 1)
	{
		dst[len] = *src;
		src++;
		len++;
	}
	dst[len] = 0;
	return (ft_strlen(dst) + ft_strlen(src));
}

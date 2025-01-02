/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:51:35 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/06 12:01:39 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*ss1 != *ss2)
		{
			return (*ss1 - *ss2);
		}
		ss1++;
		ss2++;
	}
	return (0);
}

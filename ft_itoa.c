/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:57:27 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/19 11:50:13 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_aux(int aux)
{
	int	len;

	len = 0;
	while (aux > 0)
	{
		aux = aux / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	int	aux;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == 0)
		return (ft_strdup("0"));
	aux = n;
	len = ft_aux(aux);
	char *result = malloc(len + 1 + (n < 0));
	if (!result)
		return (NULL);
	result[len + (n < 0)] = '\0';
	if (n < 0)
		result[0] = '-';
	aux = len;
	while (len--)
	{
		result[aux] = n % 10 + '0';
		n /= 10;
		aux--;
	}
	return (result);	
}

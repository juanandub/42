/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:57:27 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/19 13:11:38 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_aux(int aux, int n)
{
	int	len;

	len = 1;
	while (aux /= 10)
	{
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	char *result;
	
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_aux(n, n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0){
		result[0] = '-';
		n = -n;
	}
	len--;
	while (n)
	{
		result[len--] = n % 10 + '0';
		n /= 10;
	}
	return (result);	
}

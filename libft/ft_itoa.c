/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:21:42 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/16 15:23:13 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
 * limits returns a valid buffer on some edge test cases
 * */
char	*ft_limits(int num)
{
	char	*result;

	if (num == 0)
	{
		result = malloc(sizeof(char) * 2);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	else if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}
/*
 * overflow cannot be handled here,
 * */

char	*ft_stralloc(int num, int sign)
{
	char	*result;
	long	temp;
	int		len;

	temp = num;
	len = 0;
	while (temp > 0 && ++len)
	{
		temp /= 10;
	}
	result = malloc(sizeof(char) * (len + sign + 1));
	if (!result)
		return ((void *)0);
	ft_memset(result, '0', len + sign + 1);
	result[len + sign] = '\0';
	if (sign)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 0;
	str = ft_limits(n);
	if (str != NULL)
		return (str);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str = ft_stralloc(n, sign);
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && n > 0)
	{
		str[(len--) - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

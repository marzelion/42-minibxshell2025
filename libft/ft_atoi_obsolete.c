/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:24:02 by smrtinez          #+#    #+#             */
/*   Updated: 2025/07/08 09:38:49 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isminusplus(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi_deprec(const char *nptr)
{
	int	result;
	int	sign;
	int	len;

	result = 0;
	len = ft_strlen(nptr);
	sign = 1;
	if (len == 0)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_isminusplus(*nptr))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (result < 0)
			return (-1);
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:24:02 by smrtinez          #+#    #+#             */
/*   Updated: 2025/07/08 09:44:55 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

int	ft_isminusplus(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	not_toler(const char *s)
{
	size_t	res;
	size_t	digits;

	digits = 0;
	res = 0;
	while (*s != '\0')
	{
		if (ft_isalpha(*s))
			return (1);
		if (ft_isspace(*s))
			res++;
		if (ft_isdigit(*s++))
			digits++;
	}
	if (digits == 0)
		return (1);
	if (res > 1)
		return (1);
	return (0);
}

/*
 * this atoi converts value backwards!! omitting digits 
 * after strlen pointer is one step beyond \0, so -2 first!!!
 *  *result should be zero, no more lines
 *  validate result ptr is not null in the while loop for normi
 * possible bug? while ((--nptr > (nptr - len--)) ok
 * NORMINETTE LINE 48!!
 * */
int	ft_atoi_val(const char *nptr, int *result)
{
	unsigned int	len;
	unsigned int	mult;

	len = 0;
	while (*nptr++ != '\0')
		len++;
	if (!len || !result || ((len > 0) && (not_toler(nptr - len - 1))))
		return (-1);
	mult = 1;
	*result = 0;
	nptr -= 1;
	while (nptr > (nptr - len--))
	{
		if (ft_isminusplus(*--nptr) || ft_isspace(*nptr))
			break ;
		if (!ft_isdigit(*nptr))
			return (-1);
		*result = *result + (*nptr - '0') * mult;
		if (*result < 0)
			return (-1);
		mult *= 10;
	}
	if (*(nptr) == '-')
		*result *= -1;
	return (0);
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

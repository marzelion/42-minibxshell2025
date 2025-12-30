/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:51:45 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/16 13:47:30 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthex(unsigned long long n, unsigned int base, const char *digits)
{
	int	count;

	count = 0;
	if (n >= base)
		count += ft_puthex(n / base, base, digits);
	return (count + ft_putchar(digits[n % base]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:03:53 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/09 17:43:41 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n, size_t *printed, size_t *i)
{
	if (n < 0)
	{
		ft_putchar('-', printed);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, printed, i);
	ft_putchar(n % 10 + 48, printed);
	if (n < 10)
		(*i)++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:02:36 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/09 18:06:19 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int n, size_t *printed, size_t *i)
{
	if (n > 9)
		ft_put_unsigned_nbr(n / 10, printed, i);
	ft_putchar(n % 10 + 48, printed);
	if (n < 10)
		(*i)++;
}

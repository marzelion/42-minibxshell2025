/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:23:04 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/09 17:44:35 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(long long unsigned n, size_t *printed, size_t *i, int flag)
{
	char	*base;
	char	*nll;

	nll = "(nil)";
	base = "0123456789abcdef";
	if (!n)
	{
		ft_putstr(nll, printed, i);
		return ;
	}
	if (!flag)
	{
		ft_putchar('0', printed);
		ft_putchar('x', printed);
		flag++;
	}
	if (n > 15)
		ft_putptr(n / 16, printed, i, flag);
	ft_putchar(base[n % 16], printed);
	if (n < 16)
		(*i)++;
}

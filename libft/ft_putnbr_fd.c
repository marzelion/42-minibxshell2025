/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:16:49 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/16 12:30:04 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putnbr_fd(int nb, int fd)
{
	size_t	resultcnt;

	if (nb < 0)
	{
		resultcnt = ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			resultcnt += ft_putnbr_fd(2, fd);
			resultcnt += ft_putnbr_fd(147483648, fd);
		}
		else
			resultcnt += ft_putnbr_fd(-nb, fd);
	}
	else if (nb < 10)
	{
		resultcnt = ft_putchar_fd('0' + nb, fd);
	}
	else
	{
		resultcnt = ft_putnbr_fd(nb / 10, fd);
		resultcnt += ft_putnbr_fd(nb % 10, fd);
	}
	return (resultcnt);
}

size_t	ft_putnbr(int nb)
{
	return (ft_putnbr_fd(nb, 1));
}

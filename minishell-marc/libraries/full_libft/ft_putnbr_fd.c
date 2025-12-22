/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:28:42 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/28 02:04:19 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			digit = n + 48;
			write(fd, &digit, 1);
		}
	}
}
/*int     main()
{
        int     n = 45542;
        ft_putnbr_fd(n, 1);
        write(1, "\n", 1);
        n = -25;
        ft_putnbr_fd(n, 1);
        write(1, "\n", 1);
        n = 0;
        ft_putnbr_fd(n, 1);
        write(1, "\n", 1);
        ft_putnbr_fd(-2147483648, 1);
        ft_putnbr_fd(-42, 1);
}*/

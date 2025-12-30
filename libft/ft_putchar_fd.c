/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:58:11 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/10 17:58:32 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putchar_fd(char c, int fd)
{
	size_t	result;

	result = write(fd, &c, 1);
	if (result != 1)
		result = 0;
	return (result);
}

size_t	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}

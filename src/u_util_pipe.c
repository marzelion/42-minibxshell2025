/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_util_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/02 14:13:19 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mx_utils.h"
#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>


int _errno(void *p)
{
	if (errno)
		ft_printf("%p: ", p);
	return (errno);
}
	
int ft_isatty()
{
	int ret;
	
	ret = !isatty(0);
	if (errno != 0)
		errno = 0;
	return (ret);
}

int ft_pipeclose(int pd[3])
{
	int	t;

	if (!pd)
		return (0);
	if (pd[2] == -1)
		return (1);
	t = pd[0];
	if (close(pd[0]) + close(pd[1]) || !ft_memset(pd, 0, 2 * sizeof(int)))
	{
		ft_putnbr_fd(t, 2);
		perror(" Closing pipe:");
		return (1);
	}
	pd[2] = -1;
	return (0);
}

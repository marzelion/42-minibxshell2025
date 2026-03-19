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
#include <stdlib.h>
#include <errno.h>

/*
 * our special pipe is a int[3] where [2] is pipe error
 * if pd is [2], program will terminate
 * 
 * */
int ft_pipe(int *pd, int special, int force)
{
	if ((!pd) || (pd && special && (write(2, pd + 2, 0) != -1) && errno))
	{
		perror("ft_pipe not special!rtfm:");
		exit(-1);
	}
	if (special)
	{
		if ((pd[2] != -1) && !force)
			return (0);
		else if ((pd[2] != -1) && force)
			ft_pipeclose(pd);
	}
	if (pipe(pd) != 0)
	{
		perror("ft_pipe:");
		return (-1);
	}
	if (special)
		pd[2] = -1;
	return (0);
}

int ft_pipeclose(int *pd)
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


int _errno(void *p)
{
	if (errno)
		ft_printf("%p: ", p);
	return (errno);
}
	
int ft_tty()
{
	int ret;
	if (errno != 0)
		perror("warn_pre ft_tty_");
	errno = 0;
	ret = !isatty(0);
	if (errno != 0)
		errno = 0;
	return (ret);
}

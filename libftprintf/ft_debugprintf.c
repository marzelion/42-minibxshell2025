/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/02 14:13:19 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>

/*
 * 
 * NEED SOME IMPROVEMENTS!!!!!
 * ft_printf("ft_close - -%d-:%s \n", fd, strerror(errno));
 
int	ft_close(int fd)
{
	int	errval;

	errval = 0;
	if (fd <= 0)
		return (-1);
	if (close(fd) < 0)
	{
		errval = errno;
	}
	return (errval);
}
 * */
int	ft_close(int fd)
{
	return (close(fd));
}

#if defined(_DEBUG_ALL)

int	ft_debug_printf(int retcode, const char *fmt, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, fmt);
	result = ft_printfv(fmt, ap);
	if (result <= 0)
		ft_printf("%d", result);
	va_end(ap);
	return (retcode);
}
#elif defined(_DEBUG_PRINTF)

int	ft_debug_printf(int retcode, const char *fmt, ...)
{
	int			result;
	va_list		ap;

	va_start(ap, fmt);
	result = ft_printfv(fmt, ap);
	if (result < 0)
		ft_printf("%d", result);
	va_end(ap);
	return (retcode);
}
#else

int	ft_debug_printf(int retcode, const char *fmt, ...)
{
	(void)fmt;
	return (retcode);
}
#endif

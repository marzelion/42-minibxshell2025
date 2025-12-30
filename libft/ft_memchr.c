/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:26:26 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/14 08:33:07 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 *The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.
REM: the C standard groups strings and mem on the same lib
 * */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sptr;
	unsigned char		uc;

	sptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*sptr == uc)
		{
			return ((void *)sptr);
		}
		sptr++;
	}
	return ((void *)0);
}
/*	while (n--)
	{
		if (ft_strncmp((const char *)s++, (const char *)&c, 1) == 0)
		{
			return ((void *) s);
		}
	}
	return ((void *)0);
*/

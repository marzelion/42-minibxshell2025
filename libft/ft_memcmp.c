/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:09:10 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/19 15:07:39 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *The  memcmp()  function compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.
	If n is zero, the return value is zero. otherw difference between
	unsigned char
 *
 * */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (!n)
		return (n);
	while (n && (*ps1 == *ps2))
	{
		if (n > 1)
		{
			ps1++;
			ps2++;
		}
		n--;
	}
	return ((*(unsigned char *)ps1) - (*(unsigned char *)ps2));
}

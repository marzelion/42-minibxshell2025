/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:03:19 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/17 11:05:25 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * TODO: optimize: optimize search if biglen - len , len
 * len is SEARCH LEN!!!
 * */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	t_size_t	litlen;

	litlen = ft_strlen(little);
	if (!litlen)
		return ((char *)big);
	if (!len || !ft_strlen(big) || (litlen > len))
		return ((void *)0);
	while (len && ft_strncmp(big, little, litlen) != 0)
	{
		if (*big == '\0')
			return ((void *)0);
		if (len - 1 < litlen)
			return ((void *)0);
		big++;
		len--;
	}
	return ((char *)big);
}

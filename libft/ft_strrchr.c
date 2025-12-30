/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:09:03 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/16 13:32:32 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastocurrence;

	lastocurrence = (void *)0;
	while (*s)
	{
		if (*s == c)
			lastocurrence = (char *)s;
		s++;
	}
	if (c == '\0' && (*s == (char)c))
		return ((char *)s);
	if (*s)
		return ((char *)s);
	return (lastocurrence);
}

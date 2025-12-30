/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:39:49 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/19 15:58:54 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	comparel;
	int		result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n <= len1 && n <= len2)
		comparel = n;
	else if (len1 < len2)
		comparel = len1 + 1;
	else
		comparel = len2 + 1;
	result = ft_memcmp(s1, s2, comparel);
	return (result);
}

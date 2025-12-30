/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:17:29 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/17 11:35:13 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DOES NOT CRASH if NULL or length incorrect returns empty
 Allocates memory (using malloc(3)) and returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len’.*
NOTE: s is a valid C/string, do not take strlen in accont
my strdup prepares the buffer and copies the n bytes!!!
DOUBLE CHECKED that ft_strndupn DOES NOT need +1!!

 *
	if (!slen || !len || (start >= slen) || (start + len > slen))
 * */
#include "libft.h"
#include <stdlib.h>

char	*ft_strndupn(const char *s, t_size_t n)
{
	char		*result;

	result = (char *) malloc((n + 1));
	if (!result)
		return ((void *)0);
	ft_memset(result, 0, n + 1);
	ft_strlcpy(result, s, n + 1);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	t_size_t	slen;

	if (!s)
		return ((void *)0);
	slen = ft_strlen(s);
	if (!slen || !len || (start >= slen))
		return (ft_strdup(""));
	if (len > slen)
		return (ft_strndupn(s + start, slen));
	return (ft_strndupn(s + start, len));
}

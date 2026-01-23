/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:57:11 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/17 12:06:09 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *ft_strjoin
char *ft_strjoin(char const *s1, char const *s2);
Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2’.
not apply if (!s1 || !s2)
		return ((void *)0);
 * */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	t_size_t	s1len;
	t_size_t	s2len;

	s1len = 0;
	if (s1)
		s1len = ft_strlen(s1);
	s2len = 0;
	if (s2)
		s2len = ft_strlen(s2);
	result = (char *)malloc(s1len + s2len + 1);
	if (!result)
		return ((void *)0);
	ft_bzero(result, s1len + s2len + 1);
	if (s1len > 0)
		ft_strlcat(result, s1, s1len + s2len + 1);
	if (s2len > 0)
		ft_strlcat(result, s2, s1len + s2len + 1);
	return (result);
}

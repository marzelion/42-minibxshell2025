/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:46:23 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/15 14:44:45 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strsplit_size(char **arridx)
{
	size_t	result;

	result = 0;
	while (*arridx)
	{
		arridx++;
		result++;
	}
	return (result);
}

char	**ft_strsplit_release(char ***arr)
{
	char	**arridx;
	char	*str;

	if (arr)
	{
		arridx = *arr;
		if (arridx)
		{
			while (*arridx)
			{
				str = *arridx;
				if (str)
				{
					free(str);
					str = NULL;
				}
				arridx++;
			}
			free (*arr);
			*arr = NULL;
		}
	}
	return (NULL);
}

char	*ft_strndupn2(const char *s, t_size_t n)
{
	char		*result;
	t_size_t	len;

	if (!s)
		return ((void *)0);
	len = ft_strlen(s);
	result = (char *) malloc((len + 1));
	if (!result)
		return ((void *)0);
	ft_memset(result, 0, len +1);
	len = ft_strlcpy(result, s, n);
	n = len;
	return (result);
}

/*char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, n);
	//dup[n] = '\0';
	return (dup);
}
*/
int	ft_countfilledsubstr(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

/*
 *
	if (!s)
		return (NULL);
 * */
char	**ft_split(char const *s, char c)
{
	int			num_substrings;
	char		**result;
	char const	*start;
	char const	*end;
	int			i;

	num_substrings = ft_countfilledsubstr(s, c);
	result = malloc(sizeof(char *) * (num_substrings + 1));
	if (!result)
		return (NULL);
	start = s;
	end = s;
	i = 0;
	while (*end)
	{
		end = ft_strchr(start, c);
		if (end == NULL)
			end = s + ft_strlen(s);
		if (end > start)
			result[i++] = ft_strndupn2(start, end - start + 1);
		start = end + 1;
	}
	result[i] = NULL;
	return (result);
}

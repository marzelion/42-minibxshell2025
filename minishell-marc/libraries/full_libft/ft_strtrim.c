/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:22:34 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/25 18:25:37 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen((char *)s1))
		return (ft_strdup(""));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen((char *)s1) - 1;
	if (ft_strlen((char *)s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	return (new_str(s1, i, j - (i - 1)));
}
/* 
int main(void)
{
	char *s1 = "	Hello, World!	";
	char *set = " ";
	char *trimmed;

	trimmed = ft_strtrim(s1, set);
	if (trimmed)
	{
		printf("Original: \"%s\"\n", s1);
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}
	else
	{
		printf("failed.\n");
	}

	return 0;
} */

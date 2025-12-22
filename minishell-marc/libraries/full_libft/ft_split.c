/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:51:07 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/28 18:31:03 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*allocate_word(char const *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (*s && *s != c)
	{
		word[len] = *s;
		len++;
		s++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all_memory(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[i] = allocate_word(s, c);
			if (!result[i])
				return (free_all_memory(result, i - 1), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
/*int	main(void)
{
	char **result;
	char *test_str = "this is a c test c another c  ";
	char delimiter = 'c';
	int i = 0;
	result = ft_split(test_str, delimiter);
	
	if (result) 
	{
		printf("Original string: \"%s\"\n", test_str);
		printf("Split by delimiter '%c':\n", delimiter);
		while (result[i]) 
		{
			printf("[%d]: \"%s\"\n", i, result[i]);
			i++;
		}
		free_split(result);
	} else {
		printf("Memory allocation failed!\n");
	}
	return 0;
}*/

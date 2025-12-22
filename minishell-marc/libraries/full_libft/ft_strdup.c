/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:58:44 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/23 16:29:17 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*new_str;

	if (str == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
		size++;
	size = size + 1;
	new_str = malloc(size * sizeof(char));
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*int	main()
{
	char	string[] = "marc";
	char	*copy;

	printf("Here the original string: %s\n", string);
	copy = ft_strdup(string);
	printf("Here the copy string: %s\n", copy);
	free(copy);
}*/

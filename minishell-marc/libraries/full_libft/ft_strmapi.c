/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:36:00 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/27 23:55:16 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	if ((!s) || (!f))
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*static char	f(unsigned int i, char c)
{
	return(c + i);
}

int	main()
{
	char	*name = "marc";
	char	*result;

	result = ft_strmapi(name, f);
	if (result)
	{
		printf("Heres the 'name' string: %s", name);
		printf("\nHeres the 'result' string: %s", result);
		free(result);
	}
	else
		printf("Failed memory allocation or invalid input.");
}*/

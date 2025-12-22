/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:52:09 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:07:50 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	size_t		i;
	const char	*p;

	p = ptr;
	i = 0;
	while (i < n)
	{
		if (*p == (char)value)
			return ((void *)p);
		p++;
		i++;
	}
	return (NULL);
}
/*int main(void)
{
    char buffer[] = "Hello, World!";
    int character = 'l';
    size_t length = sizeof(buffer);

    char *result = (char *)ft_memchr(buffer, character, length);

    if (result != NULL)
    {
        printf("'%c' found at position: %ld\n", character, result - buffer);
    }
    else
    {
        printf("'%c' not found withfirst %zu bytes.\n", character, length);
    }
    return 0;
}
int	main()
{
	char	string[] = "25$ is a lot of money";
	char	*ocurrence = ft_memchr(string, 97, 20);
	if (*ocurrence != 0)
		printf("Found the charater i was looking at here: \n%s", ocurrence);
	return (0);
}*/

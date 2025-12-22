/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:10:51 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 23:52:14 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ben;

	ben = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			ben = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)ben);
}
/*int	main()
{
	char name[] = "marc fernandez cruz";
	char	*p;
	p = ft_strrchr(name, 99);
	printf("should be cruz: %s", p);
}
int main(void)
{
    const char *str = "Hello, World!";
    int ch = 'o';
    
    char *result = ft_strrchr(str, ch);
    
    if (result)
        printf("The last '%c' is at position: %ld\n", ch, result - str);
    else
        printf("Character '%c' not found in the string.\n", ch);
    
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:46:45 by marcfer3          #+#    #+#             */
/*   Updated: 2025/11/19 16:16:05 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		new_string_lengh;
	int		s1_lengh;
	int		s2_lengh;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	s1_lengh = ft_strlen(s1);
	s2_lengh = ft_strlen(s2);
	new_string_lengh = s1_lengh + s2_lengh + 1;
	new_string = ft_calloc(new_string_lengh, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (*s1)
		*new_string++ = *s1++;
	while (*s2)
		*new_string++ = *s2++;
	*new_string = '\0';
	return (new_string - (new_string_lengh - 1));
}
/*int	main()
{
	char	s1[] = "marc fernandez";
	char	s2[] = " cruz";
	char	*s3 = ft_strjoin(s1, s2);
	printf("new string result of concatenation is:\n%s", s3);
	free(s3);
}*/

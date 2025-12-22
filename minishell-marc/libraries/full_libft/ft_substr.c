/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:19 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/28 17:10:26 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		total_len;

	if (!s)
		return (NULL);
	total_len = ft_strlen((char *)s);
	if (start > total_len - 1)
		len = 0;
	else if (start + len > total_len)
		len = total_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = s[start + len];
	}
	return (result);
}
/*int main(void)
{
    const char *original_str = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;
    char *substring;
    char *substring2;

    printf("Original string: %s\n", original_str);

    substring = ft_substr(original_str, start, len);
    if (substring)
    {
        printf("Substring: %s\n", substring);
        free(substring); // Don't forget to free the allocated memory
    }
    else
    {
        printf("Failed to create substring.\n");
    }
    substring2 = substr(original_str, start, len);
    if (substring2)
    {
        printf("Substring: %s\n", substring2);
        free(substring2); // Don't forget to free the allocated memory
    }
    else
    {
        printf("Failed to create substring.\n");
    }

    return 0;
}*/

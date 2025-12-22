/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:38:31 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/26 23:49:35 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
		n = n * (-1);
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*recursion(long n, char *result, int i)
{
	if (n < 0)
	{
		n = n * (-1);
		result [0] = '-';
	}
	if (n == 0)
		result[i - 1] = '0';
	else
	{
		result[i - 1] = n % 10 + '0';
		i--;
		if (n / 10 != 0)
		{
			n = n / 10;
			recursion (n, result, i);
		}
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	new;

	new = (long)n;
	size = count_size(new);
	if (new < 0)
		size += 1;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	recursion(new, result, size);
	result[size] = '\0';
	return (result);
}
/*int main(void)
{
    int numbers[] = {0, 42, -42, 2147483647, -2147483648};
    char *str;
    int i = 0;

    while (i < 5)
    {
        str = ft_itoa(numbers[i]);
        printf("Integer: %d, String: %s\n", numbers[i], str);
        free(str);
        i++;
    }

    return 0;
}*/

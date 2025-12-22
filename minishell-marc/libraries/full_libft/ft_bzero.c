/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:08:14 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/19 14:12:16 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	char	*temp;

	temp = (char *)ptr;
	while (num > 0)
	{
		*temp = 0;
		temp++;
		num--;
	}
}
/*int	main()
{
	char	array[4] = "Marc";
	printf("%s\n", array);
	ft_bzero(array, 4);
	printf("%s", array);
}*/

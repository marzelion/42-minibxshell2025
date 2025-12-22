/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:24 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/16 16:10:27 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}
/*int	main(){

	if(ft_isalpha('c') == 1)
		write(1, "Is true\n", 8);
	else
		write(1, "Is false\n", 9);
	if(ft_isalpha('C') == 1)
                write(1, "Is true\n", 8);
        else
                write(1, "Is false\n", 9);
	if(ft_isalpha('A') == 1)
                write(1, "Is true\n", 8);
        else
                write(1, "Is false\n", 9);
	if(ft_isalpha('a') == 1)
                write(1, "Is true\n", 8);
        else
                write(1, "Is false\n", 9);
	if(ft_isalpha('0') == 1)
                write(1, "Is true\n", 8);
        else
                write(1, "Is false\n", 9);
	if(ft_isalpha('%') == 1)
                write(1, "Is true\n", 8);
        else
                write(1, "Is false\n", 9);
	
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:11:47 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 21:44:23 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*int	main()
{
	if (ft_isascii('c') == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if (ft_isascii('%') == 1)
                write(1, "1", 1);
        else
                write(1, "0", 1);
	if (ft_isascii(128) == 1)
                write(1, "1", 1);
        else
                write(1, "0", 1);
	if (ft_isascii(-2) == 1)
                write(1, "1", 1);
        else
                write(1, "0", 1);
}*/

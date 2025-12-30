/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:09:10 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/19 15:07:39 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_perror(int retval, const char *s, int ignore, int succ)
{
	if (succ)
		perror(s);
	else if (retval == -1)
		perror(s);
	if (ignore != -1)
		return (ignore);
	return (retval);
}

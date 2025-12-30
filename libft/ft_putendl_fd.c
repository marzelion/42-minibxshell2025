/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:21:59 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/10 18:22:29 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	return (ft_putstr_fd(s, fd) + ft_putchar_fd(c, fd));
}

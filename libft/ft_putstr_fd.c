/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:00:04 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/10 18:06:40 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putstr(char *s)
{
	return (ft_putstr_fd(s, 1));
}

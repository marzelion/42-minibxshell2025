/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:06:41 by marcfer3          #+#    #+#             */
/*   Updated: 2026/02/05 11:06:41 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"

int	ft_buffers_init(int size, t_cmdsanit *cmd)
{
	cmd->shadow = ft_calloc(size + 1, sizeof(char));
	if (!cmd->shadow)
		return (-1);
	return (0);
}

void	ft_add_char_shadow(int status, t_cmdsanit *cmd, int position)
{
	if (status == 0)
		cmd->shadow[position] = '1';
	else if (status == 1)
		cmd->shadow[position] = '0';
}

void	ft_init_operators(t_iterators *it, int *i)
{
	it->s_status = 0;
	it->d_status = 0;
	it->seg_len = 0;
	it->j = *i;
	return ;
}

//int	ft_check_quotes_status()
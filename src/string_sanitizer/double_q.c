/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:19:11 by marcfer3          #+#    #+#             */
/*   Updated: 2026/02/05 10:19:11 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"

//0 no se interpreta, 1 sí

char	*ft_look_for_quotes(t_cmdsanit *cmd)
{
	int		i;
	int		j;
	char	*buffer;

	j = 0;
	buffer = ft_calloc(ft_no_dq_string_len(cmd) + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (cmd->str[i])
	{
		if (cmd->str[i] == '"' && cmd->shadow[i] == '1')
		{
			i++;
			continue ;
		}
		buffer[j] = cmd->str[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

int	ft_no_dq_string_len(t_cmdsanit *cmd)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (cmd->str[i])
	{
		if (cmd->str[i] == '"' && cmd->shadow[i] == '1')
		{
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

int	ft_dqsanit(t_cmdsanit **cmd)
{
	int		i;
	char	*buffer;

	i = 0;
	while (cmd[i])
	{
		buffer = ft_look_for_quotes(cmd[i]);
		if (!buffer)
			return (-1);
		free(cmd[i]->str);
		if (cmd[i]->shadow)
			free(cmd[i]->shadow);
		cmd[i]->shadow = NULL;
		cmd[i]->str = buffer;
		i++;
	}
	return (0);
}
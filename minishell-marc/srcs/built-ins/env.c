/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:26:46 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/15 22:26:46 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **envs_array)
{
	int	i;

	i = 0;
	while (envs_array[i] != NULL)
	{
		ft_printf("%s\n", envs_array[i]);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:04:19 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/15 23:04:19 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **argvs)
{
	int 	i;
	int	flag;

	flag = 0;
	i = 1;
	while (argvs[i])//1
	{
		if (ft_strncmp(argvs[i], "echo", 5) == 0)//1
		{
			if (!argvs[i + 1])
			{		
				ft_printf("\n");
				ft_exit(0);
			}
			else if (ft_strncmp(argvs[i + 1], "-n", 2) == 0)//1+1=2
				flag = 1;
			break;
		}
		i++;
	}
	i++;//advance index 1 position to skip printing "echo"
	if (flag == 1)
		i++;//skip -n if there's any 
	while (argvs[i] != NULL)
	{
		ft_printf("%s", argvs[i]);
		if (argvs[i + 1])
			ft_printf(" ");
		if (argvs[i + 1] == NULL && flag == 0)
			ft_printf("\n");
		i++;
	}
}
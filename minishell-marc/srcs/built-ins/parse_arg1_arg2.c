/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg1_arg2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:27:45 by marvin            #+#    #+#             */
/*   Updated: 2026/01/08 18:27:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_ignore_argv1_argv2(char **argvs, int argc)
{
	char	**line_argvs;
	int		i;
	int		j;

	line_argvs = NULL;
	if ((ft_strncmp(argvs[0], "./minishell", 12) == 0) && (ft_strncmp(argvs[1], "-c", 3) == 0))
	{
		line_argvs = ft_calloc(argc - 2 + 1, sizeof(char *));//-2 because skips argv0 and argv1, +1 for NULL
		if (!line_argvs)
			ft_exit(1);
		i = 2;
		j = 0;
		//DEBUG: -> este while puede que de leaks
		while (i < argc && argvs[i])
		{
			line_argvs[j] = ft_strdup(argvs[i]);
			i++;
			j++;
		}
		line_argvs[j] = NULL;
	}
	return (line_argvs);
}
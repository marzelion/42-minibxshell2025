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
char	**ft_caso_1(char **line_argvs, char **argvs, int argc)
{
	int	i;
	int	j;

	line_argvs = ft_calloc(argc - 2 + 1, sizeof(char *));//-2 because skips argv0 and argv1, +1 for NULL
	if (!line_argvs)
		ft_exit(1);
	i = 2;
	j = 0;
	while (i < argc && argvs[i])
	{
		line_argvs[j] = ft_strdup(argvs[i]);
		i++;
		j++;
	}
	line_argvs[j] = NULL;
	return (line_argvs);
}

char	**ft_caso_2(char **line_argvs, char **argvs)
{
	int	i;
	int	j;
	int	argcounter;

	argcounter = 0;
	while (argvs[argcounter])
		argcounter++;
	line_argvs = ft_calloc(argcounter - 1 + 1, sizeof(char *));//-1 because skips argv0, +1 for NULL
	if (!line_argvs)
		ft_exit(1);
	i = 1;//->1 porque se salta solo el primer argumento, que sería <<program_name>>
	j = 0;
	while (argvs[i] && i < argcounter)
	{
		line_argvs[j] = ft_strdup(argvs[i]);
		i++;
		j++;
	}
	line_argvs[j] = NULL;
	return (line_argvs);
}

char	**ft_ignore_argv1_argv2(char **argvs, int argc, char *program_name)
{
	char	**line_argvs;

	line_argvs = NULL;
	if ((ft_strncmp(argvs[0], "./minishell", 12) == 0) && (ft_strncmp(argvs[1], "-c", 3) == 0))
		line_argvs = ft_caso_1(line_argvs, argvs, argc);
	else if (ft_strncmp(argvs[0], program_name, ft_strlen(program_name) + 1) == 0)
		line_argvs = ft_caso_2(line_argvs, argvs);
	return (line_argvs);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:20:31 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/22 11:36:19 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int argc, char **argvs, char **envp)
{
	int		i;
	char	*line;
	char	**line_argvs;

	(void)argc;
	i = 0;
	while (1)
	{
		line = readline("> ");
		if (!line)//EOF, cntlr+D
			break;
		if (line)
		{
			line_argvs = ft_split(line, ' ');
			if (ft_strncmp(line_argvs[i], "pwd", 4) == 0)
				ft_pwd();
			else if (ft_strncmp(line_argvs[i], "envp", 5) == 0)
				ft_env(envp);
			else if (ft_strncmp(line_argvs[i], "cd", 3) == 0)
				ft_cd(argvs);
			else if (ft_strncmp(line_argvs[i], "echo", 5) == 0)
				ft_echo(argvs);
			//ft_free_array(line_argvs);
			ft_free_array(line_argvs);
		}
		free(line);
	}	
}
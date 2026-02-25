/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:29:11 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/17 16:29:14 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line_bonus.h"
#include "ft_printf.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishellx.h"
#include "pipex.h"
#include "envmgr.h"

/*
typedef struct s_mx_pwd
{
	int			pipeok;
	int			pd[2];
	char		*buf;
	struct stat	s0;
	struct stat	s1;
} t_mx_pwd;

typedef struct s_minishell
{
	int				interactive;
	int				batchmode;
	t_envmanager	envm;
	t_mx_pwd		wdm;
} t_minishell,	t_msh, t_mini;
*/
typedef char* (*t_prompt)(char *);
/*
char	*ft_prompt(char *val)
{
	if (!val || (val && (*val == '\0')))
		return (0);
	if (ft_putstr_fd(val, 1) == ((size_t)-1))
		perror(NULL);
	return (0);
}
*/

/*
void t_mini_rnl(t_mini *pm)
{
//	while ((handle_multiline_input(&ctx, &input, ps1, "$")) != NULL)
	//{}
}
*/
/*int t_mini_loop()
{
	
	
	return (0);
}*/
/*int t_mini_init(t_mini *pm)
{
	if (!pm)
		return (1);
		
	return (0);
}*/

int prs(t_mini *pm, int argc, char **argv)
{
	if (!pm || (argc == 0) || !argv)
		return (-1);
	pm->interactive = 1;
	return (_errno(&prs));
}
	/*pm->interactive = argc == 1;*/
	/*if (!pm->envm.find("PWD") || !pm->envm.find("PS1") || !pm->envm.find("PS2"))
		return(t_mini_dtor(pm) != NULL);
*/

char *prompt(t_mini *p, char *level)
{
	char	*val;
	
	if (!p || !level || (level && (*level == '\0')))
		return (NULL);
	if (p->evm.find(&p->evm, level, &val))
	{
		if (*val != '\0')
			return (val);
		else
			return (val);
	}
	return ("Minishell> ");
}

/*
 * p->batchmode 
 *  >1 ignore multiple construction, DO NOT DESTROY!!
 * */
int	main(int argc, char **argv, char **envp)
{
	t_mini	x;
	int		e;
	char	*line;

	ft_bzero(&x, sizeof(t_minishell));
	e = prs(t_m_ctor(&x, ft_isatty(), envp, pipe((int *)x.evm.pd)), argc, argv);
	if (e == 0)
	{
		while(1)
		{
			if (x.batchmode == 0)
				line = readline("Minishell> ");
			else
				line = get_next_line(0);
			if (!line)
				break ;
			//sanear
	//> echo marc
			//piipex
				//pipex_minishell -> builtins o no
					//execv
			//ft_printf("%s", line);
			test_sanitizer(line);
			if (x.batchmode == 0)
				ft_putchar_fd('\n', 1);
			free(line);
		}
	}
	return (t_mini_dtor(&x));
}

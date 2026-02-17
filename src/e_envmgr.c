/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_envmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:45:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/12/29 15:45:20 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envmgr.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "ft_printf.h"

/*
 * compile cc -g -I../../libft/ envmgr.c -L../../libft -lft
 * do not use envsize = sizeof(envp);
 * */
t_envmanager	*t_evm_dtor(t_envmanager *p)
{
	if (!p)
		return (NULL);
	if (p->envp && (p->envp != p->envpbase))
		ft_strsplit_release(&p->envp);
	ft_pipeclose(p->pd);
/*	if (p->pipeenv[0] != -1)
		close(p->pipeenv[0]);
	if (p->pipeenv[1] != -1)
		close(p->pipeenv[1]);
	ft_memset(p->pipeenv, -1, 2 * sizeof(int));
	* */
	return (p);
}

/*
 * envp might be null
 * or might be alloc with 0 elements using env -i ./a.out
 * 
 * #include "ft_printf.h"
 * 	ft_printf("%p\n", envp);
	ft_printf("%p\n", *envp);
 * */ 
t_envmanager	*t_evm_ctor(t_envmanager *p, char **envp, int pipeok)
{
	if (!p)
		return (NULL);
	p->envp = NULL;
	p->envpbase = envp;
	//if ((pipeok == -1) && ft_memset(p->pipeenv, -1, 2 * sizeof(int)))
	p->pd[2] = pipeok;
	if (pipeok == -1)
		return (NULL);
	errno = 0;
	if (!envp)
		envp = malloc(sizeof(char **));
	else if (*envp != NULL)
		envp = t_evm_realloc(p, envp, NULL, 0);
	if ((errno != 0) || (envp == NULL))
	{
		ft_pipeclose(p->pd);
		perror("envp");
		return (NULL);
	}
	p->envp = envp;
	p->find = t_evm_find;
	p->create = t_evm_create;
	p->print = t_evm_print;
	return (p);
}

char	**t_evm_print(t_envmanager *p, char **kventry)
{
	char	**tmp;
	tmp = p->envp;
	while (tmp && *tmp)
	{
		ft_putstr("declare -x ");
		ft_putendl_fd(*tmp++, 1);
	}
	return (kventry);
}

# define _W 		"pipex: warn:"
char	**t_evm_realloc(t_envmanager *p, char **envp, char *add, ssize_t tsz)
{
	size_t	crtfm;	//adddz!!!!!//int		totalsize;//	char	**tmp;

	if (!p || !envp || (add && tsz && (write(p->pd[1], add, tsz) != tsz)))
		return (NULL);//totalsize += (envp - tmp) + addz;	//envp = malloc(totalsize + (addz * sizeof(char)) + 1);			//totalsize = 0;//	tmp = envp;
	while (envp && *(envp++))
	{
		if (*(envp - 1) != add)
		{//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);//crtfm = write(p->pipeenv[1], envp, ft_strlen(*envp));			//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);
			crtfm = write(p->pd[1], *(envp - 1), ft_strlen(*(envp - 1)) + 1);
			if ((tsz + ft_perror(crtfm, _W, crtfm + 1, 0))  == tsz)
				return (NULL);
		}		/*else			crtfm += ft_strlen(add) + 1;*/
		tsz += crtfm * sizeof(char);
	}
	add=NULL;
	if (FT_NEWSTR(&add, tsz) && tsz && (read(p->pd[0], add, tsz) == tsz))
		envp = ft_split_n(add, '\0', tsz);
	if (add && !ft_free(add, (void **)&add) && envp && (p->envp != p->envpbase))
		ft_strsplit_release(&p->envp);
	return (envp);
}
/*
int	main(int argc, char **argv, char **envp)
{
	t_envmanager	envm_set;
	
	(void)argc;
	(void)argv;
	if(t_evm_ctor(&envm_set, envp, pipe(envm_set.pipeenv)) == NULL)
	//if(t_evm_ctor(&envm_set, malloc(sizeof(char **)), pipe(envm_set.pipeenv)) == NULL)
		return(t_evm_dtor(&envm_set) == NULL);

	char **displayval = envm_set.find(&envm_set, "DISPLAY");
	displayval = envm_set.find(&envm_set, "SHELL");
	displayval = envm_set.find(&envm_set, "NOTFOUND");

	displayval = envm_set.create(&envm_set, NULL);
	displayval = envm_set.create(&envm_set, "");
	displayval = envm_set.create(&envm_set, "a");
	displayval = envm_set.create(&envm_set, "b");
	displayval = envm_set.create(&envm_set, "a=1");
	displayval = envm_set.create(&envm_set, "a===");
	displayval = envm_set.create(&envm_set, "a");
	displayval = envm_set.create(&envm_set, "_=hello world!");
	if(displayval && **displayval)
		**displayval = **displayval;
	envm_set.print(&envm_set, NULL);
	
	displayval = envm_set.create(&envm_set, "OLDPWD");
	char buf[255];
	char *tmp;
	tmp = ft_strjoin("PWD=", getcwd(buf, 255));
	if(tmp)
	{
		displayval = envm_set.create(&envm_set, tmp);
		free(tmp);
	}
	tmp = ft_strjoin("SHLVL=", "0");
	if(tmp)
	{
		displayval = envm_set.create(&envm_set, tmp);
		free(tmp);
	}
	tmp = ft_strjoin("_=", argv[0]);
	if(tmp)
	{
		displayval = envm_set.create(&envm_set, tmp);
		free(tmp);
	}
	displayval = envm_set.create(&envm_set, "a");
	envm_set.print(&envm_set, NULL);
	t_evm_dtor(&envm_set);
	return (0);
}
*/

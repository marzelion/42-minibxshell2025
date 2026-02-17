/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_envmgr_crud.c                                    :+:      :+:    :+:   */
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

/*
 * compile cc -g -I../../libft/ envmgr.c -L../../libft -lft
 * do not use envsize = sizeof(envp);
 * */
/*
 * watchout UNDERSCORE '_' character
 * */
int	is_validkey(const char *n)
{
	if ((n == NULL) || (*n == '\0') || (ft_strlen_delim((char *)n, '=') > 255))
		return (0);
	/*if ((*n == '_') && (*(n + 1) == '='))
		return (1);*/
	if ((*n != '=') && !ft_isalpha(*n) && (*n != '_'))
		return (0);
	while (*++n && (*n != '='))
		if (!(ft_isalnum(*n) || *n == '_'))
			return (0);
	return (1);
}

char	**t_evm_find(t_envmanager *p, char *key, char **val)
{
	char	**tmp;
	int		f;

	if (!p || !is_validkey(key))
		return ((void *)0);
	tmp = p->envp;
	while (tmp && *tmp)
	{
		f = ft_strncmp(*tmp, key, ft_strlen_delim(key, '=') + 1);
		if ((f == -'=') || (f == '=') || (f == 0))
		{
			if (val)
				*val = ft_strchr(*tmp, '=');
			return (tmp);
		}
		tmp++;
	}
	return (NULL);
}

/*
 * find will check validity of name foo valid 0foo not,
 * =equals might be or not
 * create a + create a, only once
 * create a= + create a= modifes the entry
 * create a + create a=value modfies
 * if(!p || !is_validkey(kvpair) !kvpair || (kvpair && ft_strlen(kvpair) == 0)) 
 * */
char	**t_evm_create(struct s_envmanager *p, char *kvpair)
{
	char **found;
	char **tmp;
	
	if(!p || !is_validkey(kvpair))
		return (NULL);
	found = t_evm_find(p, kvpair, NULL);
	if (found)
	{
		if (ft_strchr(kvpair, '=') == NULL)
			return (p->print(p, found));
		tmp = found;
		free(*tmp);
		*tmp = ft_strdup(kvpair);//found = malloc(sizeof(char **));//*found = ft_strdup(kvpair);//free(*tmp);//free(tmp);
		return (found);
	}
	else
		tmp = t_evm_realloc(p, p->envp, kvpair, ft_strlen(kvpair) + 1);
	if ((errno != 0) || (tmp == NULL))
		perror(NULL);
	p->envp = tmp;
	return (t_evm_find(p, kvpair, NULL));
}

int t_evm_default(t_envmanager *p)
{
	if (!p)
		return (0);
	return (1);
/*	char buf[255];
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
	tmp = ft_strjoin("PS1=", argv[0]);
	if(tmp)
	{
		displayval = envm_set.create(&envm_set, tmp);
		free(tmp);
	}	
	tmp = ft_strjoin("PS2=", argv[0]);
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
	* */
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


 * ----zzprint
 * char **tmp;
	tmp = envm_set.envp;
	while (tmp && *tmp)
	{
		ft_putendl_fd(*tmp, 1);
		//totalsize += ft_strlen(*envp) * sizeof(char);
		tmp++;
	}
//	ft_putendl_fd("\n", 1);
	
	----------
 * 
int envref_main(int argc, char **argv,  char **envp)
{
	int envsize;
	int envdif;
	char **envp;
	char **tmp;
	
	envsize = 0;
	envp = envp;
	while ((envp) && (*envp))
	{
		envsize++;
		envp++;
	}
	envsize++;
	envdif = envp - envp;
	envp = envp;
	envp = malloc((envsize) * sizeof(char **));
	if (!envp)
		return (envp != NULL);
	ft_memcpy(envp, envp, (envsize) * sizeof(char **));
	
	tmp = envp;
	while(*tmp)
	{
		if(**tmp)
			ft_putendl_fd(*tmp, 2);
		tmp++;
	}
	free(envp);
	ft_putnbr_fd(envsize, 2);
	return (0);
}
* */
/*
int _env_pipe_main(int argc, char **argv,  char **envp)
{
	int	totalsize;
	//int envsize;
	int envdif;
	char **_newenvp;
	char **tmp;
	int pipeenv[2];
	
	if (pipe(pipeenv) != 0)
		return (1);
	//envsize = 0;
	totalsize = 0;
	_newenvp = envp;
	while (envp && *envp)
	{
		totalsize += ft_strlen(*envp) * sizeof(char);
		envp++;
	}
	envdif = (envp - _newenvp) + totalsize;
	envp = _newenvp;
	write(pipeenv[1], envp, envdif);
	_newenvp = malloc(envdif);
	if(!_newenvp)
	{
		close(pipeenv[0]);
		close(pipeenv[1]);
		return (1);
	}
	read(pipeenv[0], _newenvp, envdif);
	tmp = _newenvp;
	while (tmp && *tmp)
	{
		ft_putendl_fd(*tmp, 2);
		//totalsize += ft_strlen(*envp) * sizeof(char);
		tmp++;
	}
	free(_newenvp);
	close(pipeenv[0]);
	close(pipeenv[1]);
	return (0);
}
*/

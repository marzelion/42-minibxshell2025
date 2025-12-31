/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:45:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/12/29 15:45:20 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
/*
 * compile cc -g -I../../libft/ envmgr.c -L../../libft -lft
 * do not use envsize = sizeof(envp);
 * */
/*
typedef struct s_envmanager
{
	const char	**_envp_bas;
	char		**_envp;
	int			size;
	char **(*init)(s_envmanager *p, char **envp);
	char **(*find)(s_envmanager *p, char *key);
	char **(*remove)(s_envmanager *p, char *key);
	char *(*at)(s_envmanager *p, char *key);
}	t_envmanager;

t_envmanager *t_evm_dtor(t_envmanager *p)
{
	if (!p)
		return (NULL);
	if (p->_envp)
	{
		ft_strsplit_release(&p->_envp);
	}
	p->_envp_base = NULL;
}
t_envmanager *t_evm_init(t_envmanager *p, char **envp)
{
	const char **envpp;
	const char **itenv;;

	envpp = envp;
	p->_envp = malloc((p->size + 1)*sizeof(char **));
	if (!p->_envp)
		return (NULL);
	
	//ft_memcpy(p->_envp, 
	 
	itenv = p->_envp;
	while(envp)
	{
		itenv = ft_strdup(*envp);
		if (!itenv)
		{
			ft_strsplit_release(&p->_envp);
			return (NULL);
		}
		envp++;
		itenv++;
	}
	return (p);
}
t_envmanager *t_evm_ctor(t_envmanager *p, char **envp)
{
	if (!p)
		return (NULL);
	p->init = t_evm_init;
	p->find = t_evmg_find;
	p->at = t_evmg_at;
	p->_envp_base = envp;
	p->size = 0;
	while(p->_envp_base++)
		p->size++;
	return (t_evm_init(p, envp));
}

char **t_evmg_find(t_envmanager *p, char *key)
{
	char **envp;
	if (!p || !key)
		return ((void *)0);
	if (ft_strlen(key) == 0)
		return ((void *)0);
	envp = p->_envp_base;
	while (*envp)
		if (ft_strncmp(*envp, key, ft_strlen(key)) == '=')
			return (envp);
	return (NULL);
}

char **t_evmg_remove(t_envmanager *p, char *key)
{
	char **oldenvp;
	char **remove;
	
	oldenvp = p->find(p, key);
	if (oldenvp)
	{
		remove = oldenvp;
		free(*remove);
		*remove = (void *)0;
		while(++remove)
		{
			oldenvp = remove;
			oldenvp++;
		}
	}
}

char *t_evmg_at(t_envmanager *p, char *key)
{
	char **result;
	
	result = p->find(p, key);
	if (result)
		return (ft_strchr(*result, '=');
	return NULL
}
*/
typedef struct s_envmanager
{
	int		pipeenv[2];
	char	**_envp;
	char	**(*find)(struct s_envmanager *p, char *key);
	char	**(*create)(struct s_envmanager *p, char *kvpair);
}	t_envmanager;

t_envmanager	*t_evm_dtor(t_envmanager *p)
{
	if (!p)
		return (NULL);
	if (p->_envp)
		ft_free((void *)p->_envp, (void **)&p->_envp);
	if (p->pipeenv[0] != -1)
		close(p->pipeenv[0]);
	if (p->pipeenv[1] != -1)
		close(p->pipeenv[1]);
	ft_memset(p->pipeenv, -1, 2 * sizeof(int));
	return (p);
}
# define _W 		"pipex: warn:"
char	**t_evm_realloc(t_envmanager *p, char **envp, char *add, size_t addz)
{
	size_t	crtfm;
	adddz!!!!!//int		totalsize;//	char	**tmp;

	if (!p)
		return (NULL);
	totalsize = addz * sizeof(char);//	tmp = envp;
	while (envp && *envp)
	{
		if (*envp != add)
		{
			crtfm = ft_putstr_fd((char *)(envp), p->pipeenv[1]);//crtfm = write(p->pipeenv[1], envp, ft_strlen(*envp));			//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);
			if ((totalsize + ft_perror(crtfm, _W, crtfm + 1, 0))  == totalsize)
				return (NULL);
			totalsize += crtfm * sizeof(char);
		}
		envp++;
	}
	if (add && (addz > 0) && (write(p->pipeenv[1], add, addz) != addz))
		return (NULL);//totalsize += (envp - tmp) + addz;	//envp = malloc(totalsize + (addz * sizeof(char)) + 1);
	envp = ft_calloc(1, totalsize + 1);
	if (envp && totalsize && (read(p->pipeenv[0], envp, totalsize) != -1))
		perror(NULL);
	if (envp && p->_envp)
		ft_free((void *)p->_envp, (void **)&p->_envp);
	return (envp);
}
	/*totalsize = 0;
	tmp = envp;
	while (envp && *envp)
		if (envp != add)
		totalsize += ft_strlen(*(envp++)) * sizeof(char);
	if (write(p->pipeenv[1], tmp, totalsize) != totalsize)
		return (NULL);
	if (add && (addz > 0) && (write(p->pipeenv[1], add, addz) != addz))
		return (NULL);//totalsize += (envp - tmp) + addz;
	totalsize += addz;
	envp = malloc(totalsize);
	if (envp)
		if (read(p->pipeenv[0], envp, totalsize) != totalsize)
			perror(NULL);
	if (envp && p->_envp)
		ft_free((void *)p->_envp, (void **)&p->_envp);
	return (envp);
	* */
	/*if (write(p->pipeenv[1], tmp, totalsize) == totalsize)
	{
		if (add && (write(p->pipeenv[1], add, addz) != addz))
			return (NULL);
		totalsize += addz + 1 + write(p->pipeenv[1], NULL, 1);
	}
	envp = malloc(totalsize);
	if (envp)
		if (read(p->pipeenv[0], envp, totalsize) != totalsize)
			perror(NULL);
	if (envp && p->_envp)
		ft_free((void *)p->_envp, (void **)&p->_envp);
	return (envp);
	* */

char	**t_evm_find(t_envmanager *p, char *key)
{
	char	**tmp;
	int		f;

	if (!p || !key)
		return ((void *)0);
	if (ft_strlen(key) == 0)
		return ((void *)0);
	tmp = p->_envp;
	while (tmp && *tmp)
	{
		f = ft_strncmp(*tmp, key, ft_strlen(key) + 1);
		if ((f == -'=') || (f == '=') || (f == 0))
			return (tmp);
		tmp++;
	}
	return (NULL);
}

char	**t_evm_create(struct s_envmanager *p, char *kvpair)
{
	char *pval;
	char **found;
	char **tmp;
	
	if(!p || !kvpair || (kvpair && ft_strlen(kvpair) == 0))
		return (NULL);
	found = t_evm_find(p, kvpair);
	if (found)
	{
		tmp = found;
		//found = malloc(sizeof(char **));
		//*found = ft_strdup(kvpair);
		//free(*tmp);
		//free(tmp);
		found = p->_envp;
	}
	else
		found = t_evm_realloc(p, p->_envp, kvpair, ft_strlen(kvpair));
	if ((errno != 0) || (found == NULL))
	{
		perror(NULL);
		return (NULL);
	}
	p->_envp = found;
	return (found);
}
/*
 * 
 * */
t_envmanager	*t_evm_ctor(t_envmanager *p, char **envp, int pipeok)
{
	if (!p)
		return (NULL);
	p->_envp = NULL;
	if (pipeok == -1)
	{
		ft_memset(p->pipeenv, -1, 2 * sizeof(int));
		return (NULL);
	}
	envp = t_evm_realloc(p, envp, NULL, 0);
	if ((errno != 0) || (envp == NULL))
	{
		perror(NULL);
		if(envp)
			free(envp);
		return (NULL);
	}
	if (envp)
		p->_envp = envp;
	p->find = t_evm_find;
	p->create = t_evm_create;
	return (p);
}

int	main(int argc, char **argv, char **envp)
{
	t_envmanager	envm_set;
	
	//if(t_evm_ctor(&envm_set, envp, pipe(envm_set.pipeenv)) == NULL)
	if(t_evm_ctor(&envm_set, NULL, pipe(envm_set.pipeenv)) == NULL)
		return(t_evm_dtor(&envm_set) == NULL);

	char **displayval = envm_set.find(&envm_set, "DISPLAY");
	displayval = envm_set.find(&envm_set, "SHELL");
	displayval = envm_set.find(&envm_set, "NOTFOUND");

	displayval = envm_set.create(&envm_set, NULL);
	displayval = envm_set.create(&envm_set, "");
	displayval = envm_set.create(&envm_set, "a");
	displayval = envm_set.create(&envm_set, "b");
	//displayval = envm_set.create(&envm_set, "a=1");
//	displayval = envm_set.create(&envm_set, "a===");
	//displayval = envm_set.create(&envm_set, "a");

	t_evm_dtor(&envm_set);
	return (0);
}



int envref_main(int argc, char **argv,  char **envp)
{
	int envsize;
	int envdif;
	char **_envp;
	char **tmp;
	
	envsize = 0;
	_envp = envp;
	while ((envp) && (*envp))
	{
		envsize++;
		envp++;
	}
	envsize++;
	envdif = envp - _envp;
	envp = _envp;
	_envp = malloc((envsize) * sizeof(char **));
	if (!_envp)
		return (_envp != NULL);
	ft_memcpy(_envp, envp, (envsize) * sizeof(char **));
	
	tmp = _envp;
	while(*tmp)
	{
		if(**tmp)
			ft_putendl_fd(*tmp, 2);
		tmp++;
	}
	free(_envp);
	ft_putnbr_fd(envsize, 2);
/*	t_envmanager t_e;
	
	if(!t_evm_ctor(&t_e, envp))
		return (1);
	t_e = envp;
	char **displayval = t_e.find("DISPLAY");
	char **notfoundval = t_e.find("NOTFOUND");
	//t_e->d("DISPLAY");
	*/
	/*
		_envpi["DISPLAY"] = "";
		&_envp[DISPLAY"] = NULL ????????????
	*/
	/*t_evm_dtor(&t_e);*/
	return (0);
}

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
	//envsize++;
	/*write(pipefd[1], &envdif, sizeof(int));
	envp = envp;
	while ((envp) && (*envp))
	{
		envsize = ft_strlen(*envp);
		write(pipefd[1], *envp, envsize);
		envp++;
	}*/
	//read(pipefd[0], &envsize, sizeof(int));
/*	t_envmanager t_e;
	
	if(!t_evm_ctor(&t_e, envp))
		return (1);
	t_e = envp;
	char **displayval = t_e.find("DISPLAY");
	char **notfoundval = t_e.find("NOTFOUND");
	//t_e->d("DISPLAY");
	*/
	/*
		_envpi["DISPLAY"] = "";
		&_envp[DISPLAY"] = NULL ????????????
	*/
	/*t_evm_dtor(&t_e);*/
	return (0);
}

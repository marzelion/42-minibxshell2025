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
typedef struct s_envmanager
{
	const char	**envp_bas;
	char		**envp;
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
	if (p->envp)
	{
		ft_strsplit_release(&p->envp);
	}
	p->envpbase = NULL;
}
t_envmanager *t_evm_init(t_envmanager *p, char **envp)
{
	const char **envpp;
	const char **itenv;;

	envpp = envp;
	p->envp = malloc((p->size + 1)*sizeof(char **));
	if (!p->envp)
		return (NULL);
	
	//ft_memcpy(p->envp, 
	 
	itenv = p->envp;
	while(envp)
	{
		itenv = ft_strdup(*envp);
		if (!itenv)
		{
			ft_strsplit_release(&p->envp);
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
	p->envpbase = envp;
	p->size = 0;
	while(p->envpbase++)
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
	envp = p->envpbase;
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

/*
 * watchout UNDERSCAORE '_' character
 * */
int	is_validkey(const char *n)
{
	if ((n == NULL) || (*n == '\0') || (ft_strlen_delim((char *)n, '=') > 255))
		return (0);
	/*if ((*n == '_') && (*(n + 1) == '='))
		return (1);*/
	if (!ft_isalpha(*n) && (*n != '_'))
		return (0);
	while (*++n && (*n != '='))
		if (!(ft_isalnum(*n) || *n == '_'))
			return (0);
	return (1);
}



typedef struct s_envmanager
{
	int		pipeenv[2];
	char	**envpbase;
	char	**envp;
	char	**(*find)(struct s_envmanager *p, char *key);
	char	**(*create)(struct s_envmanager *p, char *kvpair);
	char	**(*print)(struct s_envmanager *p, char **kventry);
}	t_envmanager;

t_envmanager	*t_evm_dtor(t_envmanager *p)
{
	if (!p)
		return (NULL);
	if ((p->envp) && (p->envp != p->envpbase))
		ft_strsplit_release(&p->envp);
	if (p->pipeenv[0] != -1)
		close(p->pipeenv[0]);
	if (p->pipeenv[1] != -1)
		close(p->pipeenv[1]);
	ft_memset(p->pipeenv, -1, 2 * sizeof(int));
	return (p);
}

int	ft_countfilledsubstr_n(const char *s, char c, size_t n)
{
	int	count;
	size_t i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (*s == c)
			count++;
		s++;
		i++;
	}
	return (count);
}

char	**ft_split_n(char const *s, char c, size_t n)
{
	int			num_substrings;
	char		**result;
	int			i;
	size_t			j;

	num_substrings = ft_countfilledsubstr_n(s, c, n);
	result = malloc(sizeof(char *) * (num_substrings + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < n)
	{
		result[i++] = ft_strdup(s);
		s += ft_strlen(result[i-1]) + 1;
		j += ft_strlen(result[i-1]) + 1;
	}
	result[i] = NULL;
	return (result);
}
#include "ft_printf.h"
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

/*
 *  * #include "ft_printf.h"
 * 	ft_printf("%p\n", envp);
	ft_printf("%p\n", *envp);
 * */
# define _W 		"pipex: warn:"
char	**t_evm_realloc(t_envmanager *p, char **envp, char *add, ssize_t tsz)
{
	size_t	crtfm;	//adddz!!!!!//int		totalsize;//	char	**tmp;

	if (!p || !envp || (add && tsz && (write(p->pipeenv[1], add, tsz) != tsz)))
		return (NULL);//totalsize += (envp - tmp) + addz;	//envp = malloc(totalsize + (addz * sizeof(char)) + 1);			//totalsize = 0;//	tmp = envp;
	while (envp && *(envp++))
	{
		if (*(envp - 1) != add)
		{//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);//crtfm = write(p->pipeenv[1], envp, ft_strlen(*envp));			//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);
			crtfm = write(p->pipeenv[1], *(envp - 1), ft_strlen(*(envp - 1)) + 1);
			if ((tsz + ft_perror(crtfm, _W, crtfm + 1, 0))  == tsz)
				return (NULL);
		}		/*else			crtfm += ft_strlen(add) + 1;*/
		tsz += crtfm * sizeof(char);
	}
	add=NULL;
	if (FT_NEWSTR(&add, tsz) && tsz && (read(p->pipeenv[0], add, tsz) == tsz))
		envp = ft_split_n(add, 0, tsz);
	if (add && !ft_free(add, (void **)&add) && envp && (p->envp != p->envpbase))
		ft_strsplit_release(&p->envp);
	return (envp);
}
	//if((ft_free(add, &add) == NULL) envp && (p->envp))
			//return((void *)envp +  + ft_free(p->envp, &p->envp));
		//if((ft_free(add, &add) == NULL) && envp && (p->envp))
			//ft_free((void *)p->envp, (void **)&p->envp);
	//return (envp + (char **)ft_free(add, &add));
	/*
	if (add && (read(p->pipeenv[0], *envp, totsz) != totsz))
		return (ft_free(envp, (void **)envp));	//if (*envp && totsz && (read(p->pipeenv[0], *envp, totsz) != totsz))//		return (envp);
	envp = ft_split_n(*envp, 0, totsz);
	if (add && p->envp)
		ft_free((void *)p->envp, (void **)&p->envp);
		* */
	/*while (envp && *envp)
	{
		if (*envp != add)
		{
			//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);//crtfm = write(p->pipeenv[1], envp, ft_strlen(*envp));			//crtfm = ft_putstr_fd(*envp, p->pipeenv[1]);
			crtfm = write(p->pipeenv[1], envp, ft_strlen(*envp) + 1 + sizeof(char *));
			if ((totalsize + ft_perror(crtfm, _W, crtfm + 1, 0))  == totalsize)
				return (NULL);
			totalsize += crtfm * sizeof(char);
		}
		envp++;
	}
	//if (add && (ft_putstr_fd(add, p->pipeenv[1]) == -1))
	if (add && (write(p->pipeenv[1], add, ft_strlen(add) + 1 + sizeof(char *)) == -1))
		return (NULL);//totalsize += (envp - tmp) + addz;	//envp = malloc(totalsize + (addz * sizeof(char)) + 1);
	envp = ft_calloc(totalsize + 1, sizeof(char **));
	if (envp && totalsize && (read(p->pipeenv[0], envp, totalsize) != -1))
		perror(NULL);
	if (envp && p->envp)
		ft_free((void *)p->envp, (void **)&p->envp);
		* */
	//return (envp);
//}
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
	if (envp && p->envp)
		ft_free((void *)p->envp, (void **)&p->envp);
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
	if (envp && p->envp)
		ft_free((void *)p->envp, (void **)&p->envp);
	return (envp);
	* */

char	**t_evm_find(t_envmanager *p, char *key)
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
			return (tmp);
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
 * */
char	**t_evm_create(struct s_envmanager *p, char *kvpair)
{
	char **found;
	char **tmp;
	
	if(!p || !kvpair || (kvpair && ft_strlen(kvpair) == 0))
		return (NULL);
	found = t_evm_find(p, kvpair);
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
	return (t_evm_find(p, kvpair));
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
	if ((!p) || ((pipeok == -1) && ft_memset(p->pipeenv, -1, 2 * sizeof(int))))
		return (NULL);
	p->envpbase = envp;
	p->envp = NULL;
	if (!envp)
		envp = malloc(sizeof(char **));
	else if (*envp != NULL)
		envp = t_evm_realloc(p, envp, NULL, 0);
	if ((errno != 0) || (envp == NULL))
	{
		perror(NULL);
		return (NULL);
	}
	p->envp = envp;
	p->find = t_evm_find;
	p->create = t_evm_create;
	p->print = t_evm_print;
	return (p);
}

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

/*
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

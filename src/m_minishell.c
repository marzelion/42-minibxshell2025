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
#include <errno.h>
#include <stdio.h>
#include "minishellx.h"
#include "pipex.h"
#include "envmgr.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/*
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>


#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishellx.h"
#include "pipex.h"
#include "envmgr.h"
*/
/*
typedef struct s_minishell
{
	int				interactive;
	int				batchmode;
	t_envmanager	envm;
	t_mx_pwd		wdm;
} t_minishell,	t_msh, t_mini;

 * 
 * p->batchmode 
 * 	< 0 program end
 *  == 0 interactive
 *  == 1 batch
 *  >1 ignore multiple construction, DO NOT DESTROY!!
 * */
int	t_mini_dtor(t_mini *p)
{
	int	err;

	err = errno;
	if (!p)
		return (-1);
	if (((--p->batchmode) > 0) && (p->batchmode == ft_tty()))
		return (errno);
	if (errno)
		perror("msh: ");
	ft_pipeclose((int *)&p->wdm.pd);
	t_evm_dtor(&p->evm);
	if (p->wdm.buf)
		ft_free(p->wdm.buf, (void **)&p->wdm.buf);
	if (p->history_path)
		ft_free(p->history_path, (void **)&p->history_path);
	if (p->splitsd)
		ft_free(p->splitsd, (void **)&p->splitsd);
	if (p->tokenset)
		ft_strsplit_release(&p->tokenset);
	return (err);
}

/*
 * p->batchmode 
 *  >1 ignore multiple construction, DO NOT DESTROY!!
 * if (!x || (x && ft_memset(x->evm.pd + 2, k, sizeof(int)) && k < 0) || b < 0)
 * 	x->batchmode += b;
 * */
t_mini	*t_m_ctor(t_mini *x, char **envp, int k)
{
	if (!x || (x && (k < 0)))
		return (NULL);
	x->batchmode++;
	if (x->batchmode > 1)
		return (x);
	if (!x->splitsd || !x->tokenset)
		return (NULL);
	x->interactive = 0;
	if (t_evm_ctor(&x->evm, envp, k) == NULL)
		return (NULL);
	x->wdm.buf = NULL;
	if (t_mini_default(x, FTPIPE(x->wdm.pd, 1, 0) != 0))
		return (NULL);
	x->history_path = NULL;
	return (x);
}

/*
 * getenv("SHLVL")
 * */
int	ft_shlvl(t_mini *x)
{
	char	*val;
	int		intval;
	char	*str;

	if (!x)
		return (-1);
	str = (char *)SHLVL1_DEF;
	if (x->evm.find(&x->evm, "SHLVL", &val))
	{
		if (ft_atoi_val(val, &intval) > -1)
		{
			val = ft_itoa(++intval);
			if (val)
			{
				str = ft_strjoin("SHLVL=", val);
				ft_free(val, (void **)&val);
			}
		}
	}
	x->evm.create(&x->evm, str);
	if ((str - (char *)SHLVL1_DEF) != 0)
		ft_free(str, (void **)&str);
	return (_errno(&ft_shlvl));
}

/*
 * SI QUISIERA GUARDAR EL ARCHIVO DEL HISTORIAL EN HOME, DE FORMA QUE
 *  TODOS LOS USUARIOS 	TENGAN ACCESO A SU PROPIO HISTORIAL
 *  INDEPENDIENTEMENTE DESDE DONDE EJECUTEN MINISHELL IGUALMENTE 
 * CREO QUE ES VALIDO QUE EL HISTORIAL SE GUARDE DENTRO DEL
 *  DIRECTORIO DEL PROYECTO
*/
/*if(home)
	{
		history_path = ft_calloc(ft_strlen(home) + ft_strlen("/.minishell_history" + 1, sizeof(char)));
		ft_strlen(x->evm.find("HOME")
		if (!history_path)
			ft_exit(1);
		ft_strcpy(history_path, home);
		ft_strcat(history_path, "./minishell_history");
	}
	else
		history_path = ft_srtdup("./minishell_history");
		* 
	//char	*history_path;
	/////////////////////////
	x->history_path FLAG!!!!! PARA CONFIRMAR que guardo el hstory
	
	if (x->history_path)
		add_history(line);
	
	/////////////////////////
*/
char	*ft_current_directory_history_path(t_mini *x)
{
	x->history_path = "/tmp";
	x->history_path = ft_strjoin(x->history_path, "/.minishell_history");
	if (!x->history_path)
		perror("error creating string for readline_history file\n");
	return (x->history_path);
}

/*
 * removed ft_pipeclose((int *)&p->evm.pd);
*/
int	t_mini_default(t_mini *p, int p_ok)
{
	if (!p || (p && p_ok))
		return (-1);
	if ((p->wdm.pd[2] == -1) || ft_shlvl(p) || (p->batchmode > ft_tty()))
		return (errno);
	if (ft_pwd(0, NULL, p->evm.envp, *p) || ft_current_directory_history_path(p))
		return (errno);
	return (errno);
}

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

char	*getreadline(char **line, t_prompt p)
{
	if (!line)
		return (NULL);
	if (isatty(0))
*line = readline(p(*line));//shell->prompt = readline(shell->terminal_prompt);
* 	if (!*line)	perror(NULL);
	else
	{
		errno = 0;
		*line = get_next_line(0);//shell->prompt = ft_strtrim(line, "\n");
	}
	if (errno)
	{
		perror(NULL);
		*line = NULL;
	}
	return (*line);
}*/

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
}

int prs(t_mini *pm, int argc, char **argv)
{
	if (!pm || (argc == 0) || !argv)
		return (-1);
	pm->interactive = argc == 1;
	if (!pm->envm.find("PWD") || !pm->envm.find("PS1") || !pm->envm.find("PS2"))
		return(t_mini_dtor(pm) != NULL);
	return (errno);
}*/
/*
int ft_shlvl(t_mini x)
{
	(void)x;
	int		val;
	char	*kv;
	
	kv = x.envm.v(&x.envm, "SHLVL");
	if (!kv)
		val = 0;
	else if (ft_atoi_val(kv, &val) == -1))
		val = 0;
	kv = ft_itoa(val);
	if (!kv)
		return(errno);
		lllllllllllllllllllllll
	x.envm.create(&x.envm, FT_JOIN("SHLVL=", kv));
* *
	return (errno);
}
*/
/*
int	t_mini_default(t_mini *p, int p_ok)
{
	if (!p || (p && ft_memset(p->wdm.pd + 2, p_ok, sizeof(int)) && !p_ok))
		return (-1);
	if ((p->wdm.pd[2] == -1) || (p->batchmode > isatty(0)))
		return (0);
	ft_pipeclose((int *)&p->evm.pd);
//	if ((ft_pwd(0, NULL, p->evm.envp, *p) != 0) || ft_shlvl(*p))
	//	return (errno);
	return (errno);
}
*/

/*int	main(int argc, char **argv, char **envp)
{
	t_mini	x;
	int		e;

	e = prs(t_m_ctor(&x, isatty(0), envp, pipe((int *)x.evm.pd)), argc, argv);
	if (e == 0)
	{
	}
	return (t_mini_dtor(&x));
	* */
/*	t_pipex	pipex;

	if (!t_pipex_ctor(&pipex))
		return (t_pipex_dtor(&pipex));
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	if (argc == 5)
		pipex.error = pipex_empty_argvslifo(argc, argv);
	else
		ft_printf("Incorrect parameters! %d\n", argc);
	if (argc == 5)
		pipex.run(&pipex, envp);
	return (t_pipex_dtor(&pipex));
	* 
}
* */

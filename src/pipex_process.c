/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:49 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/17 16:28:53 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pipex.h"

/*
 * waitpid((*(t_procx **)p)->id, (void *)0, WNOHANG);
 * //if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			ft_putstr_fd("proces\n", 2);
			ft_putnbr_fd(WIFEXITED(status), 2);
			ft_putstr_fd("proces\n", 2);
			ft_putnbr_fd(WEXITSTATUS(status), 2);
			ft_putstr_fd("proces\n", 2);
			
		}
 * */
void	t_procx_waitforme(void *p)
{
	t_procx	*pproc;
	pid_t	pid;
	int		status;

	if (!p)
		return ;
	pproc = *(t_procx **)p;
	if (pproc->id != 0)
	{
		if ((pproc->pipex_error != 0))
		{
			pid = waitpid(pproc->id, &status, WNOHANG);
		}
		else
		{
			pid = waitpid(pproc->id, &status, 0);
		}
		ft_close(pproc->pipe[1]);
		if (pid == (pproc->id))
			pproc->id = 0;
		pproc->pipex_error = (((status) & 0xff00) >> 8);
	}
}

/*
 * grep WE  /usr/include/x86_64-linux-gnu/bits/waitstatus.h 
 * #define	__WEXITSTATUS(status)	(((status) & 0xff00) >> 8)

 * https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_wait.h.html
 * //pproc->pipe[1] = ft_close(pproc->pipe[1]);
 * //if (!list_content || !pfd || (ready == -1)) 
 * REM //   *pfd = NULL; NOT HERE, see child desrtuctor or parent before
 * dtor
 * */
t_procx	**t_procxpipe_ctor(t_procx **list_content, int **pfd, int ready)
{
	if ((list_content != NULL) && (pfd != NULL) && (ready == 0))
	{
		(*list_content) = malloc(sizeof(t_procx));
		if ((*list_content) != NULL)
		{
			(*list_content)->id = -1;
			(*list_content)->cmd = NULL;
			(*list_content)->argv = NULL;
			(*list_content)->pipe = *pfd;
			(*list_content)->wc = 0;
			(*list_content)->pipex_error = ready;
			(*list_content)->pre = t_procx_pre;
			return (list_content);
		}
	}
	if (list_content != NULL)
		free(list_content);
	list_content = NULL;
	if (pfd != NULL)
		if (*pfd != NULL)
			free(*pfd);
	pfd = NULL;
	return (NULL);
}

/*
 * (FT_DBGPRINT(0, "- bad dtor t_procx  - \n"))
 * */
void	t_procx_dtor(void *pp)
{
	t_procx	**pprx;

	if (!pp)
		return ;
	pprx = (t_procx **)pp;
	if (!*pprx)
	{
		free(pprx);
		pprx = NULL;
		return ;
	}
	ft_strsplit_release(&(*pprx)->argv);
	if (((*pprx)->cmd) != NULL)
	{
		free((*pprx)->cmd);
		(*pprx)->cmd = NULL;
	}
	if ((*pprx)->pipe != NULL)
		free((*pprx)->pipe);
	(*pprx)->pipe = NULL;
	free(*pprx);
	*pprx = NULL;
	free(pprx);
	pprx = NULL;
	return ;
}

/*
 * * s =? ls = /bin + / + ls <-- assgined to t_procx->cmd
 * s =? /bin/ppepepe/ls?? exec MIGHT FAIL OR NOT!! <-- NOT assigned!! 
 * theres a extra malloc to append "/"!! free to evita leak!
 * if split,  build /path/to/bin+ "/" + split[0]
 * */
char	*t_procx_pre(t_procx *p, const char *s, char **env)
{
	char	*temp;

	if (p && s)
	{
		if (ft_strlen(s) > 0)
		{
			p->argv = ft_split(s, ' ');
			if (!p->argv)
				FT_DBGPRINT(0, "cmd split %s\n", strerror(errno));
			else if (*p->argv)
			{
				if ((p->argv[0][0] == '/') || (ft_strlen(p->argv[0]) < 2))
					return (p->argv[0]);
				temp = ft_strjoin(BACK_SLASH, p->argv[0]);
				p->cmd = build_path(temp, env);
				free(temp);
				temp = NULL;
				if (p->cmd)
					return (p->cmd);
			}
		}
	}
	return (NULL);
}

/*
 * 		//t_procx_dtor(&p);
		//t_pipex_dtor(ppx);
		* ft_strsplit_release(&p->argv);
		* EKEYEXPIRED = 126
//return (ft_putstr_fd("ppx - dnuof ton dnammoc\n", 2)); 
 * */
int	t_procx_exec(t_procx *p, char *cmd, t_pipex *ppx)
{
	int	result;

	if (!p || !cmd || !ppx)
	{
		if (execve("", p->argv, ppx->envp) == -1)
			p->pipex_error = 127 + ENOKEY - EKEYEXPIRED + 1;
		return (ft_putendl_fd(strerror(errno), 2));
	}
	else if (p->argv && *p->argv)
	{
		if (p->cmd != NULL)
			result = execve(p->cmd, p->argv, ppx->envp);
		else
			result = execve(p->argv[0], p->argv, ppx->envp);
	}
	else
		result = execve(cmd, p->argv, ppx->envp);
	p->pipex_error = errno;
	perror(NULL);
	if ((p->pipex_error == ENOENT) && (p->cmd))
		p->pipex_error = EKEYEXPIRED;
	if ((p->pipex_error == ENOENT) && (p->argv[0][0] != '/'))
		p->pipex_error = errno;
	return (result - result);
}

/*
 * ft_putnbr_fd(errno, 2);
 * ft_putnbr_fd(p->pipex_error, 2);
 * p->pipex_error = errno;
	result = ft_putstr_fd("ppx - ", 2) + ft_putstr_fd(p->argv[0], 2);
	if ((errno == ENOENT) && (p->argv[0][0] != '/'))
		return (ft_putstr_fd(": command not found\n", 2));
	result = ft_putstr_fd(" ", 2) + ft_putstr_fd(strerror(errno), 2) * result;
	return (ft_putstr_fd("\n", 2));
 * 
 * STDIN_FILENO; 0 STDOUT_FILENO; 1
 * 
 * 
void	t_pipex_run_cmd_deprec(void *p)
{
	(void)p;
}

	t_pipex	*pthis;
	int		id;
	int		result;
	char 	**argv;
	
	pthis = (t_pipex *)p;
	if(!pthis)
		return ;	
	id = fork();
	if (id == -1)
	{
		FT_DBGPRINT(1, "fork error\n");
		return ;
	}
	if (id == 0)
	{		
		if ((dup2(fdin, 0) == -1) || (dup2(fdout, 1) == -1))
		{
			FT_DBGPRINT(1, "- ignore - %s\n", strerror(errno));			
		}
		FT_DBGPRINT(1, "child exec->");
		close(fdin);
		close(fdout);
		argv = ft_split(cmd, ' ');		
		//debug_splitstr(envp);
		FT_DBGPRINT(0, "argv0 %s\n", argv[0]);
		if (*argv != NULL)
		{
			result = execve(argv[0], argv, envp);
			ft_strsplit_release(&argv);
			FT_DBGPRINT(result, "failed, %d", result);
			//debug_splitstr(argv);
		}
		FT_DBGPRINT(1, "child finish\n");
	}
	else
	{
		FT_DBGPRINT(1, "parrent wwait\n");
		//wait(NULL);
	}
*/

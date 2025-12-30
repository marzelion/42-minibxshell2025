/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:24:42 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/09 11:24:49 by smrtinez         ###   ########.fr       */
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
#include <string.h>
#include "pipex.h"

/*
 * pthis->ppfd should be NULL unless procx failed
 * */
int	t_pipex_dtor(t_pipex *pthis)
{
	int		last_err;
	t_list	*pnode;

	if (!pthis)
		return (-1);
	last_err = pthis->error;
	pnode = ft_lstlast(pthis->child);
	if (pnode)
		if (pnode->content != NULL)
			if ((*(t_procx **)pnode->content) != NULL)
				last_err = (*(t_procx **)pnode->content)->pipex_error;
	if (pthis->child != (void *)0)
		ft_lstclear(&pthis->child, t_procx_dtor);
	pthis->child = NULL;
	if (pthis->ppfd != NULL)
	{
		free(pthis->ppfd);
		pthis->ppfd = NULL;
	}
	if (pthis->outfilefd == -1)
		last_err = 1;
	pthis->release_fds(pthis, 1);
	return (last_err);
}

/*
  	//if (((last_err == 0) || (last_err > 0)) && (pthis->outfilefd == -1))
 * if (pipe2(pipefd,  O_CLOEXEC) == -1)
 * */
t_pipex	*t_pipex_ctor(t_pipex *pthis)
{
	if (!pthis)
		return ((void *)0);
	ft_bzero(pthis, sizeof(t_pipex));
	pthis->this = pthis;
	pthis->error = 0;
	pthis->argc = 0;
	pthis->argv = (void *)0;
	pthis->argv_it = -1;
	pthis->envp = (void *)0;
	pthis->child = (void *)0;
	pthis->lim = NULL;
	pthis->outfilefd = -1;
	pthis->infilefd = -1;
	pthis->ppfd = NULL;
	pthis->prepare_fds_argc = t_pipex_prepare_fds_argc;
	pthis->release_fds = t_pipex_release_fds;
	pthis->init_proc = t_pipex_init_proc;
	pthis->run = t_pipex_run;
	return (pthis->this);
}

/*
 * 0 return is a fatal error, to exit program
 * if exec fails, as we are the child 0 process, the fork has to dtor normally
 * note is added to the process list anyway
 * REM: pl = ft_lstnew(ppcx); ->content = ppcx
 * if (FT_DBGPRINT((*ppcx)->id, "fork %d\n", (*ppcx)->id) == -1)
 * rem: if (a > 0 && b > 0 && (b / 0) > 1) { // div not checked!!
 * if (!pre)
			ft_close((*(t_procx **)pl->content)->pipe[1]);
		waitpid((*(t_procx **)pl->content)->id, (void *)0, 0);
	//int jajaja;
	//char tmp[8]="hcdlihc";
 * */
int	t_pipex_init_proc(t_pipex *px, char *cmd, t_procx **ppcx, t_procx *pre)
{
	t_list	*pl;

	if (px && cmd && t_procxpipe_ctor(ppcx, &px->ppfd, pipe(px->ppfd)))
	{
		pl = ft_lstnew(ppcx);
		t_pipex_redirect_parent(px, *ppcx);
		if (pl)
		{
			ft_lstadd_back(&px->child, pl);
			(*ppcx)->id = fork();
			if ((*ppcx)->id == -1)
				return (FT_DBGPRINT(t_pipex_dtor(px), "bye: fork\n"));
			if (((*ppcx)->id) == 0)
			{
				if (t_pipex_redirect_child(t_pipex_dup_s(px), *ppcx, pre) > -1)
					t_procx_exec(*ppcx, (*ppcx)->pre(*ppcx, cmd, px->envp), px);
				px->ppfd = NULL;
				exit(t_pipex_dtor(px));
			}
			t_pipex_release_fds(px, px->infilefd);
			return ((*ppcx)->id);
		}
	}
	t_procx_dtor(ppcx);
	return (FT_DBGPRINT(0, "t_px eyerll not init %s\n", strerror(errno)));
}

/*
 * * */
t_procx	*t_prevprocx(t_pipex *pt)
{
	if (!pt)
		return (NULL);
	if (ft_lstsize(pt->child) == 0)
		return (NULL);
	return (*(t_procx **)(ft_lstlast(pt->child))->content);
}

/*
 * if (FT_DBGPRINT(pt->ppfd == NULL, "%s\n", strerror(errno)))
 *  <- prints "Success"!!
 * //if (pt->init_proc(pt, cmd, container, t_prevprocx(pt)) < 1)
			//return ;
 * //ft_lstiter(pt->child, t_procx_waitforme);
 * */
void	t_pipex_run(t_pipex *pt, char **e)
{
	char		*cmd;
	t_procx		**container;

	(void)e;
	if (!pt)
		return ;
	pt->argv_it = 2;
	if ((pt->prepare_fds_argc(pt) == 1) && (pt->lim != NULL))
		pt->argv_it++;
	while (pt->argv_it < (pt->argc -1))
	{
		cmd = pt->argv[pt->argv_it];
		pt->ppfd = malloc(2 * sizeof(int));
		if (pt->ppfd == NULL)
			return ;
		container = malloc(sizeof(t_procx **));
		pt->init_proc(pt, cmd, container, t_prevprocx(pt));
		container = NULL;
		pt->ppfd = NULL;
		pt->argv_it++;
		ft_lstiter(pt->child, t_procx_waitforme);
	}
	pt->release_fds(pt, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:26 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/17 16:28:31 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pipex.h"

int	t_pipex_to_fds(t_pipex *ppx)
{
	if (ppx != NULL)
	{
		if (ppx->ppfd)
		{
			ppx->infilefd = ppx->ppfd[1];
			ppx->heredoc = ppx->ppfd[0];
		}
	}
	return (0);
}

/*
int	prepare_file(const char *fpathf, int *oflag, int mod)
{
	int			resultfd;
	struct stat	statbuf;	

	if (!oflag)
		exit(254);
	*oflag = open(fpathf, *oflag | O_CLOEXEC, mod);
	resultfd = *oflag;
	if (resultfd < 0)
	{
		return (FT_DBGPRINT(resultfd, "%s", strerror(errno)));
	}
	if (fstat(resultfd, &statbuf) < 0)
	{
		ft_close(resultfd);
		return (FT_DBGPRINT(resultfd, "%s", strerror(errno)));
	}
	if (!S_ISREG(statbuf.st_mode) && !S_ISFIFO(statbuf.st_mode))
	{
		ft_close(resultfd);
		return (FT_DBGPRINT(resultfd, "%s", strerror(errno)));
	}
	return (resultfd);
}

		resultfd = open("/dev/null", newflags, mod);
		if (resultfd == -1)
			return (ft_printf("ppx fatal : %s", strerror(errno)) == 0);
	//fpathf = "/dev/stdin";
*/
int	filex_prp(const char *fpathf, int *oflag, int mod, char *special)
{
	int	resultfd;

	if (!oflag)
		exit(254);
	if ((special != NULL) && ((*oflag & O_RDONLY) == O_RDONLY))
		return (dup(0));
	*oflag = open(fpathf, *oflag | O_CLOEXEC, mod);
	resultfd = *oflag;
	if (resultfd < 0)
	{
		ft_putstr_fd("ppx - ", 2);
		ft_putstr_fd((char *)fpathf, 2);
		ft_putstr_fd(":", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (FT_DBGPRINT(*oflag, "\n"));
	}
	return (resultfd);
}

/*
 * FT_DBGPRINT(0, "Parse %d\n", cnt);
 	if (ft_strlen(argv[cnt]) < 1)
	{
		return (FT_DBGPRINT(1, "Parse error, %d size <2\n", cnt));
	}
	cnt--;
	if (ft_strlen(argv[cnt--]) < 1)
		return (FT_DBGPRINT(1, "d:error, outfile name empty\n"));
	while (cnt > 1)
	{
		cnt--;
	}
	if (ft_strlen(argv[cnt]) < 1)
		return (FT_DBGPRINT(1, "d:error, infile name empty\n"));
	return (0);
* 
* non blocking error, but set the error flag for unexpected...
 * */
int	pipex_empty_argvslifo(int cnt, char **argv)
{
	cnt--;
	if (ft_strlen(argv[cnt--]) < 1)
		return (1);
	while (cnt > 1)
	{
		cnt--;
	}
	if (ft_strlen(argv[cnt]) < 1)
		return (1);
	return (0);
}

/*
 * 	FT_DBGPRINT(0, "t_pipex_release_fds %d\n", pthis->infilefd);
	FT_DBGPRINT(0, "t_pipex_release_fds %d\n", pthis->outfilefd);
	if (pthis->pipefd[0] != -1)
		ft_close(pthis->pipefd[0]);
	pthis->pipefd[0] = -1;
	if (pthis->pipefd[1] != -1)
		ft_close(pthis->pipefd[1]);
	pthis->pipefd[1] = -1;
 * */
void	t_pipex_release_fds(t_pipex *pthis, int close_files)
{
	if (pthis == NULL)
		return ;
	if ((pthis->infilefd > 2) && (close_files == pthis->infilefd))
	{
		ft_close(pthis->infilefd);
		pthis->infilefd = -1;
	}
	if ((pthis != NULL) && close_files == 1)
	{
		if (pthis->infilefd > 0)
			ft_close(pthis->infilefd);
		if (pthis->outfilefd != -1)
			ft_close(pthis->outfilefd);
		pthis->infilefd = -1;
		pthis->outfilefd = -1;
	}
}

/*
 * O_NOFOLLOW
 * 	ppx->pipefd[0] = -1;
	ppx->pipefd[1] = ppx->pipefd[0];
	if (pipe(ppx->pipefd) == -1)
		return (FT_DBGPRINT(-1, "%s\n", strerror(errno)));
	..return (FT_DBGPRINT(ppx->infilefd, " i:%s \n",ppx->argv[1]));
	ppx->error = ft_printf("ppx-i %s:%s\n", ppx->argv[1], strerror(errno));
ppx->error = 1;

/usr/include/asm-generic/fcntl.h
#define O_ACCMODE   00000003 #define O_RDONLY    00000000 
#define O_WRONLY    00000001 #define O_RDWR      00000002 ...
 * */
int	t_pipex_prepare_fds_argc(t_pipex *ppx)
{
	int	l;

	if (!ppx)
		exit(-1);
	if (ppx->argc > 2)
	{
		if (ft_strncmp(HERE_DOC_S, ppx->argv[ppx->argv_it - 1], 9) == 0)
			ppx->lim = ppx->argv[ppx->argv_it++];
		l = O_RDONLY;
		ppx->infilefd = filex_prp(ppx->argv[1], &l, 0, ppx->lim);
		if ((ppx->infilefd == -1) || (l < 0))
			ppx->error = 1;
	}
	if ((ppx->argc > 4) || ((ppx->lim == NULL) && (ppx->argc > 3)))
	{
		l = O_WRONLY | O_CREAT | O_TRUNC;
		if (ppx->lim != NULL)
			l = O_WRONLY | O_CREAT | O_APPEND;
		ppx->outfilefd = filex_prp(ppx->argv[ppx->argc - 1], &l, 0644, NULL);
		if ((ppx->outfilefd == -1) || (l < 0))
			ppx->error = 2;
	}
	return (ppx->error);
}

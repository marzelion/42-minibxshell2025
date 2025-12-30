/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:29:29 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/17 16:29:33 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line_bonus.h"
#include "ft_printf.h"
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
 * watchout pipe creation error pt->argv_it!!
 * if init_process returns 0, we are on an errand child, NOT in parent!!
 * 	//process_cmd(argv[2], envp, infilefd, outfilefd);
	//process_cmd(argv[3], envp, infilefd, outfilefd);
	* if (command)
 * */
char	*build_path(const char *command, char *envp[])
{
	char	**envp_split;
	char	*ppstr;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			envp = ft_split((*envp + 5), ':');
			envp_split = envp - 1;
			while (*(++envp_split))
			{
				ppstr = ft_strjoin(*envp_split, command);
				if (access(ppstr, X_OK) == 0)
					break ;
				free(ppstr);
				ppstr = NULL;
			}
			ft_strsplit_release(&envp);
			if (!ppstr)
				ppstr = ft_strdup(command + 1);
			return (ppstr);
		}
		envp++;
	}
	return (ft_strdup(command));
}

	/*char	**envp_split;
	char	*ppstr;
	
	if (envp != NULL)
		while (*(envp++))
		{
			if (ft_strncmp(*(envp - sizeof(char **)), "PATH=", 5) != 0)
				continue ;
			envp = ft_split((*(envp - sizeof(char **)) + 5), ':');
			envp_split = envp - 1;
			while (*(++envp_split))
			{
				ppstr = ft_strjoin(*envp_split, command);
				if (access(ppstr, X_OK) == 0)
					break ;
				free(ppstr);
				ppstr = NULL;
			}
			ft_strsplit_release(&envp);
			if (!ppstr)
				ppstr = ft_strdup(command);
			return (ppstr);
		}
	return (ft_strdup(command));
	* */
/*
 * fdin/fdout might be -1!
  * STDIN_FILENO; 0 STDOUT_FILENO; 1
 * 
 * */
int	ft_dup2_ex(int fdin, int fdout)
{
	int	result;

	if (fdin == -1)
	{
		result = dup2(fdin, fdout);
		FT_DBGPRINT(1, "%s", strerror(errno));
		return (0);
	}
	if ((fdin == -1) || (fdout == -1))
		return (-1);
	result = dup2(fdin, fdout);
	if (result == -1)
	{
		FT_DBGPRINT(1, "duPP2x %d %s\n", result, strerror(errno));
	}
	return (result);
}

/*
 t_pipex	*t_pipex_dup_s(t_pipex *ppx)
{
	if (ppx == NULL)
		return (ppx);
	if ((ppx->argv_it == 3) && (ppx->lim != NULL))
	{
		if (ft_dup2_ex(ppx->heredoc, 0) + ft_close(ppx->heredoc) < 0)
			ft_putstr_fd(strerror(errno), 2);
		//ppx->heredoc = -1;
		if (ft_close(ppx->infilefd) < 0)
		//if (ft_close(ppx->ppfd[0])  < 0)
			ft_putstr_fd(strerror(errno), 2);
		//ppx->infilefd = -1;
	}
	//ppx->ppfd = NULL;
	if (ppx->infilefd == -1 && ft_dup2_ex(open(D_NULL, O_RDONLY, 0), 0) != 0)
		ft_putstr_fd(strerror(errno), 2);
	if (ppx->outfilefd == -1)
		ppx->outfilefd = open(D_NULL, O_WRONLY, 0666);
	if (ppx->outfilefd == -1)
		ft_putstr_fd(strerror(errno), 2);
	return (ppx);
} 
*/
t_pipex	*t_pipex_dup_s(t_pipex *ppx)
{
	if (ppx == NULL)
		return (ppx);
	if ((ppx->argv_it == 3) && (ppx->lim != NULL))
	{
		if (ft_dup2_ex(ppx->heredoc, 0) + ft_close(ppx->heredoc) < 0)
			ft_putstr_fd(strerror(errno), 2);
		if (ft_close(ppx->infilefd) < 0)
			ft_putstr_fd(strerror(errno), 2);
	}
	if (ppx->infilefd == -1 && ft_dup2_ex(open(D_NULL, O_RDONLY, 0), 0) != 0)
		ft_putstr_fd(strerror(errno), 2);
	if (ppx->outfilefd == -1)
		ppx->outfilefd = open(D_NULL, O_WRONLY, 0666);
	if (ppx->outfilefd == -1)
		ft_putstr_fd(strerror(errno), 2);
	return (ppx);
}

/*
 * fdin/fdout might be -1!
  * STDIN_FILENO; 0 STDOUT_FILENO; 1
 * pid_t pid1 = fork();
    if (pid1 == 0) { // Child process for cmd1
        dup2(fd1, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execute_command(argv[2], envp);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) { // Child process for cmd2
        dup2(pipefd[0], STDIN_FILENO);
        dup2(fd2, STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execute_command(argv[3], envp);
    }
	para concatenar forks... se llama antes del fork con is_parent=0  
	* y despues con 1, el primer fork lo redirecciona desde infile y 
	* el ultimo escribe en outfile, los intermedios usan sustituyen 
	* las entradas y salidas standard por un pipe 
 * */
/*
 * strace -f -e process /bin/bash -c "./pipex_pd /sys/power/state tee '' 
 * outfile"
 * ./pipex_pd /sys/power/state tee "" outfile
 * * STDIN_FILENO; 0 STDOUT_FILENO; 1
 int	t_pipex_redirect_parent(t_pipex *ppx, t_procx *pproc, t_procx *pre)
{	
	char	*child_cmd;
	(void)pre;
	if ((ppx == NULL) || (pproc == NULL))
		return (1);
	//if (!pre)
	//	ft_close(pproc->pipe[1]);
	//waitpid(pproc->id, (void *)0, 0);
	//if (ppx->argv_it > 2)
	//	ft_close(pproc->pipe[0]);
	child_cmd = pproc->pre(pproc, ppx->argv[ppx->argv_it], ppx->envp);
	if (!child_cmd)
		t_pipex_error(ppx, 127);
	else if (ft_strlen(child_cmd) == 0)
		t_pipex_error(ppx, 127);
	else if (access(child_cmd, X_OK) != 0)
		t_pipex_error(ppx, 1);
	//if (pre)
	//	ft_close(pre->pipe[0]);
	return (0);
}
*/
	/*if (!child_cmd)
		t_pipex_error(ppx, 0);
	else if (ft_strlen(child_cmd) == 0)
		t_pipex_error(ppx, 0);*/
	/*else if (access(child_cmd, X_OK) != 0)
		t_pipex_error(ppx, 1);
set args here_doc p shuf shuf pruebaheredoc1.txt
* heredoc case and current iteration == "3" (==first command!) 
* REM: pre is previous process, but BE CAREFUL ON FAIL!!!
* pproc->pre checks if child process command is working or 127
* BUT even on 127, the child remains listning pipe
* //while ((ft_strlen(FT_NEWSTR(&p->cmd, p->written)) > 0)
*  && ft_putstr_fd(ppx->lim,0))
* //if ((ppx->argv_it == 3) && ft_putstr_fd(ppx->lim, 0))
* if (!((ppx == NULL) && (p == NULL)) && (ppx->argv_it != 3))
*/
int	t_pipex_redirect_parent(t_pipex *ppx, t_procx *p)
{
	size_t	crtfm;

	if (!((ppx != NULL) && (p != NULL)) || !ppx->lim || (ppx->argv_it != 3))
		return (1);
	p->cmd = get_next_line(ft_putchar_fd(126, 1) - 1);
	while (FT_NEWSTR(&p->cmd, p->wc) && *p->cmd && ft_strrchr(p->cmd, '\n'))
	{
		if (ft_strncmp(ppx->lim, p->cmd, ft_strlen(ppx->lim) + 1) == -('\n'))
		{
			ft_free((void *)p->cmd, &p->cmd);
			continue ;
		}
		else
		{
			crtfm = ft_putstr_fd(p->cmd, ppx->ppfd[1]);
			p->wc += ft_perror(crtfm, _W, crtfm + 1, 0) - 1;
			ft_free((void *)p->cmd, &p->cmd);
		}
		p->cmd = get_next_line(ft_putchar_fd(126, 1) - 1);
	}
	if ((t_pipex_to_fds(ppx) == 0) && (p->wc > 0) && p->cmd)
		ft_perror(read(ppx->ppfd[0], p->cmd, p->wc), _W, -1, 0);
	if (p->wc && p->cmd && *p->cmd && ft_perror(pipe(ppx->ppfd), _W, 1, 0))
		ft_perror(write(ppx->infilefd, p->cmd, p->wc), _W, 1, 0);
	return (ft_free((void *)p->cmd, &p->cmd) != NULL);
}

/* 251205!!! Aparently potential leak!!
 * 	size_t	crtfm;

	if (!((ppx != NULL) && (p != NULL)) || (ppx->argv_it != 3))
		return (1);
	if (p->cmd)
		return (ft_perror(write(ppx->infilefd, p->cmd, ft_strlen(p->cmd) )
				, _W, 1, 0));
	p->cmd = get_next_line(ft_putchar_fd(126, 1) - 1);
	while (FT_NEWSTR(&p->cmd, p->wc) && *p->cmd && ft_strrchr(p->cmd, '\n'))
	{
		if (ft_strncmp(ppx->lim, p->cmd, ft_strlen(ppx->lim) + 1) == -('\n'))
		{
			ft_free((void *)p->cmd, &p->cmd);
			continue ;
		}
		crtfm = ft_putstr_fd(p->cmd, ppx->ppfd[1]);
		p->wc += ft_perror(crtfm, _W, crtfm + 1, 0);
		ft_free((void *)p->cmd, &p->cmd);
		p->cmd = get_next_line(ft_putchar_fd(126, 1) - 1);
	}
	ft_perror(read(ppx->ppfd[0], p->cmd, p->wc), _W, -1, 0);
	ppx->infilefd = ppx->ppfd[1];
	ppx->heredoc = ppx->ppfd[0];
	return (ft_perror(pipe(ppx->ppfd), _W, 1, 0));
 * 251205!!!
 * 
 * */

/*
        if child:
            close pipe write
            if not first:
                dup stdio to pre_pipe
            if not last:
                dup stdout curpipe
            
            ( execve o similar)            
        
        // parent
        close writepipe
    * //if ((ppx->argv_it == 3) && (ppx->lim != NULL)
    * //if ((ppx == NULL) || (pproc == NULL) || t_pipex_std_dup_safe(ppx) 
    * != 0)
    * //if ((ppx->argv_it == 2) || ((ppx->argv_it == 3) && (ppx->lim != 
    * NULL)))
 * */
int	t_pipex_redirect_child(t_pipex *ppx, t_procx *pproc, t_procx *pre)
{
	if ((ppx == NULL) || (pproc == NULL))
		return (1);
	if (ppx->argv_it == 2)
	{
		if (ft_dup2_ex(ppx->infilefd, 0) + ft_close(pproc->pipe[0]) < 0)
			return (-1);
		if ((ft_dup2_ex(pproc->pipe[1], 1) + ft_close(pproc->pipe[1])) < 0)
			return (-1);
		return (0);
	}
	else if (ppx->argv_it == (ppx->argc - 2))
	{
		if (pre)
			if (ft_dup2_ex(pre->pipe[0], 0) + ft_close(pre->pipe[0]) < 0)
				return (-1);
		if (ft_dup2_ex(ppx->outfilefd, 1) + ft_close(pproc->pipe[1]) < 0)
			return (-1);
		return (0);
	}
	if (pre)
		if (ft_dup2_ex(pre->pipe[0], 0) + ft_close(pre->pipe[0]) < 0)
			return (-1);
	if (ft_dup2_ex(pproc->pipe[1], 1) + ft_close(pproc->pipe[1]) < 0)
		return (-1);
	return (0);
}

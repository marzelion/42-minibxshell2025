/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:46 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/09 11:02:48 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLX_H
# define MINISHELLX_H

#include "envmgr.h"
#include <sys/stat.h>

typedef struct s_charpp
{
	char **v;
} t_charpp;

typedef struct s_workdirmgr
{
	int			pd[3];
	char		*buf;
	struct stat	s0;
	struct stat	s1;
} t_workdirmgr, t_wdm;

typedef struct s_minishell
{
	int				last_px;
	int				interactive;
	int				batchmode;
	char			*history_path;
	char			*splitsd;
	char			**tokenset;
	int				tkit;
	int				tkstate;
	char			*buffer;
	char			*cmd_conv;
	t_envmanager	evm;
	t_workdirmgr	wdm;
} t_minishell,	t_msh, t_mini;

/*
 * u_util_pipe.c
 * */
int		_errno(void *p);

int		ft_tty();

/*
 * m_minishell.c
 * */
int		t_mini_dtor(t_mini *p);

t_mini	*t_m_ctor(t_mini *p, char **envp, int pipeok);

# define XCTOR t_m_ctor

int		t_mini_default(t_mini *p, int p_ok);

int		ft_pwd(int c, char **v, char **e, t_msh x);

void	test_sanitizer(char *rline);

/*
# define D_NULL 		"/dev/null"
# define BACK_SLASH "/"
# define _W 		"pipex: warn:"
# define _W_D 		"pipex: warn: ctrl+D on here_doc? %s expected"
# define _PS ft_putstr_fd
# define FTPS1 ft_putchar_fd

typedef struct s_procx
{
	pid_t	id;
	char	**argv;
	char	*cmd;
	int		*pipe;
	size_t	wc;
	int		pipex_error;
	char	*(*pre)(struct s_procx *, const char *, char **);
} t_procx,	t_px;

typedef struct s_pipex
{
	struct s_pipex	*this;
	int				error;
	int				argc;
	char			**argv;
	int				argv_it;
	char			**envp;
	char			*envp_path;
	t_list			*child;
	int				heredoc;
	char			*lim;
	int				outfilefd;
	int				infilefd;
	int				*ppfd;
	int				(*prepare_fds_argc)(struct s_pipex *);
	void			(*release_fds)(struct s_pipex *, int);
	int				(*init_proc)(struct s_pipex *, char *, t_px **, t_px *);
	void			(*run)(struct s_pipex *, char **);
}	t_pipex;
*/
/*
 * pipex_process.c
 * */
/*
 * pipex_utils.c
 * */

#endif

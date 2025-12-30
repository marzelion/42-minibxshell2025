/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:46 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/09 11:02:48 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define D_NULL 		"/dev/null"
/*
# define HERE_DOC_S	"here_doc"
*/
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

/*
 * pipex_process.c
 * */
t_procx	**t_procxpipe_ctor(t_procx **list_content, int **pfd, int ready);

void	t_procx_dtor(void *pp);

char	*t_procx_pre(t_procx *p, const char *s, char **env);

int		t_procx_exec(t_procx *p, char *cmd, t_pipex *ppx);

void	t_procx_waitforme(void *p);

/*
 * pipex_utils.c
 * */
/*{
	waitpid(((t_procx *)p)->id, NULL, 0);
}
 * */
int		filex_prp(const char *fpathf, int *oflag, int mod, char *special);

int		pipex_empty_argvslifo(int cnt, char **argv);

void	t_pipex_release_fds(t_pipex *pthis, int close_files);

int		t_pipex_prepare_fds_argc(t_pipex *pthis);

int		t_pipex_to_fds(t_pipex *ppx);

/*
 * pipex.c
 * */

/*void	t_procx_waitforme(void *p);
 * */
t_pipex	*t_pipex_dup_s(t_pipex *ppx);

char	*build_path(const char *command, char *envp[]);

int		t_pipex_redirect_child(t_pipex *ppx, t_procx *pproc, t_procx *pre);

int		t_pipex_redirect_parent(t_pipex *ppx, t_procx *pproc);

int		ft_dup2_ex(int fdin, int fdout);
/*
 * pipex_main.c
 * */
int		t_pipex_dtor(t_pipex *pthis);

t_pipex	*t_pipex_ctor(t_pipex *pthis);

int		t_pipex_init_proc(t_pipex *pthis, char *cmd, t_px **ppcx, t_px *prev);

void	t_pipex_run(t_pipex *pthis, char **envp);

void	debug_splitstr(char **argv_split);

#endif

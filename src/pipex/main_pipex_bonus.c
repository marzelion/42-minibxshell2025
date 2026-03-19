/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:15:37 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/22 12:15:40 by smrtinez         ###   ########.fr       */
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
#include <sys/wait.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#include "pipex.h"

/*
 * ./pipex_pd _ls 'tr \n \128 ' sort outfile && cat outfile
 * strace -f -e process /bin/bash -c "./pipex_pd infile tee '' ''"
 * strace -f -e process ./pipex_pd "" "" "" ""

 * /bin/bash tests!
 <teeout.txt tee | tee > teeout2.txt
strace -f -e process /bin/bash -c "</sys/power/state tee | >outfile"
 * 
 * according to my test ">outfile" ALWAYS TRUNCATE outfile!!
 * create file 6
   $ >6
 * ---
 *  echo "hola" > 3
 * ---
 * VALID COMMAND but outfile is truncated but empty
 * <3 >outfile.txt
 *  -----
 * VALID COMMAND BUT destroys contents of file 3
 * <3 >3
 * ----
 * <3  cat -e
hola$
*  <3 tee > 8
* cat -e 8
hola$
* ----
tee > 8
asdasd
asdasd
~/projects/ftproj/00_clean/pipex_local$ cat 8
asdasd
asdasd



 * ./pipex_pd
 * ./pipex_pd "" "" "" ""
 * ./pipex_pd 1 22 23 4
 * */

/*

typedef struct s_procmgr
{
	int		end;
	int		proclen;
	t_list	*unit;
	
	int		(*is_end)(s_procmgr *);
	void	(*c)(s_procmgr *);
	void	(*r)(s_procmgr *);
	void	(*u)(s_procmgr *);
	void	(*d)(s_procmgr *);
	void	(*init)(s_procmgr *);
	void	(*update)(s_procmgr *, unsigned long);
	
}	t_procmgr, t_pcm;

void *t_procx_update(void *pprocx)
{
	return (NULL);
}
int t_pcm_end(t_procmgr *p)
{
	return (p->end == 1);
}

void t_pcm_init(t_procmgr *p)
{
}
void t_pcm_update(t_procmgr *p, unsigned long dt)
{
	ft_lstiter(unit, t_procx_update);
}

t_procmgr	*t_procmgr_ctor()
{
	t_procmgr	*result;
	
	result = malloc(sizeof(t_procmgr));
	if (!result)
		return (FT_DBGPRINT(NULL, "procmgr ctor: %s\n", strerror(errno)));
	result->end = 0;
	result->unit = NULL;
	result->proclen = ft_lstsize(result->unit);
	result->is_end = t_pcm_end;
	result->init = t_pcm_init;
	return (result);
}
*/
/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/

/*
 * todo pipex.prepare(&pipex, argc, argv, envp);
 * */
#ifdef _FTBONUS

void	debug_splitstr(char **argv_split)
{
	ft_printf("size:%d\n", ft_strsplit_size(argv_split));
	while (*argv_split)
	{
		ft_printf("%s\n", *argv_split);
		argv_split++;
	}
}

/*
 * 	else if (argc == 1)
		ft_printf("Incorrect parameters! %d\n", (argc - 1));
		if (argc > 5)
		{
			if (ft_strlen(pipex.argv[1]) > 0)
			{
				if (ft_strncmp(HERE_DOC_S, pipex.argv[1], 9) == 0)
					pipex.run(&pipex, envp);
			}
			pipex.run(&pipex, envp);
		}
		else
		 	pipex.run(&pipex, envp);		
		
 * */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (!t_pipex_ctor(&pipex))
		return (t_pipex_dtor(&pipex));
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	if (argc > 4)
	{
		pipex.error = pipex_empty_argvslifo(argc, argv);
		pipex.run(&pipex, envp);
	}
	return (t_pipex_dtor(&pipex));
}
#else

#endif

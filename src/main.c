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

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishellx.h"
#include "string_sanitizer.h"
#include "pipex.h"
#include "pipex_utils.h"


/*
typedef struct s_mx_pwd
{
	int			pipeok;
	int			pd[2];
	char		*buf;
	struct stat	s0;
	struct stat	s1;
} t_mx_pwd;

typedef struct s_minishell
{
	int				interactive;
	int				batchmode;
	t_envmanager	envm;
	t_mx_pwd		wdm;
} t_minishell,	t_msh, t_mini;
*/
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
*/

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
}*/

	/*pm->interactive = argc == 1;*/
	/*if (!pm->envm.find("PWD") || !pm->envm.find("PS1") || !pm->envm.find("PS2"))
		return(t_mini_dtor(pm) != NULL);
*/

char *prompt(t_mini *p, char *level)
{
	char	*val;
	
	if (!p || !level || (level && (*level == '\0')))
		return (NULL);
	if (p->evm.find(&p->evm, level, &val))
	{
		if (*val != '\0')
			return (val);
		else
			return (val);
	}
	return ("Minishell> ");
}


/*
 * sinqle quote sanitize()
 * 	convert single quote to \0 if not in double quote
 *    WARN: if exists a last single quote its an error! convert to \0
 * ft_split by \0
 * starting \0 of split, means interpret or not
 * rebuild string from splits
 * */
/*void sanitize(char **cmd, int cmdlen, int separator, char *tmp)
{
	char **splts;
	char **ps;
	int expand;

	if(!cmd || (cmd && !(*cmd)) || !ft_memset(&expand, 0, sizeof(int)))
		return ;
	if (separator == '\'')
		ft_striteri(*cmd, single_quotetozero);
	else if (separator == '\"')
		ft_striteri(*cmd, double_quotetozero);
	else
		return ;
	if ((cmdlen > 1) && ((*cmd)[cmdlen - 1] == separator))
		(*cmd)[cmdlen - 1] = '\0';
	splts = ft_split_l(*cmd, cmdlen);
	if (splts && ft_free(*cmd, (void **)cmd))
	{
		ps = splts;
		while(*(ps++))
		{
			if (**(ps - 1) == '\0')
				expand = !expand;
			if (expand)
				sanitize(ps - 1, ft_strlen(*(ps - 1)), '\"', tmp);
			// *cmd = ft_strjoin(*cmd, *(ps - 1));
		}
	}
}*/

/*
 * 	if ((cmd && *cmd == NULL) || (cmd && (**(char **)cmd) == '\0') || !*split)
		return (errno + (ft_free(*cmd, cmd) != NULL));
 * */
/*if ((xps != (*(char *)ft_memset(&xps, (**(p - 1) != 0), 1))) && !**(p - 1))
			continue ;
		if (xps && !cmd_sanitze((t_vpp)(p - 1), split + 2, ft_strlen(*(p - 1))))
		* */
		/*
		//if (((**(p - 1) != 0) != xps) && ft_memset(&xps, (**(p - 1) != 0), 1) && xps)
		ft_printf("%c", **(p));
		memset(&xps, **(p) != 0, 1);
		if (((**(p) != 0) - xps) && *(char *)memset(&xps, **(p) != 0, 1))
		//if (((**(p - 1) != 0) != xps) || (ft_memset(&xps, **(p - 1), sizeof(char))))
			if (xps && cmd_sanitze((t_vpp)(p), split + 2, ft_strlen(*(p))))
				continue ;
		tmp = FT_JOIN((char*)*cmd, *(p));
		if (tmp || (*cmd && ft_free(*cmd, cmd)))
			*((char **)cmd) = tmp; //FT_JOIN
			* */
/*int cmd_sntzsl(void **cmd, char *splt, size_t l_xp)
{
	char	**splitcmd;
	char	**p;
	char	*tmp;

	if (!cmd)
		return (-1);
	if ((cmd && *cmd == NULL) || (cmd && (**(char **)cmd) == '\0') || !*splt)
		return (errno);
	ft_striteri(*(char **)cmd, f_convert(*splt));
	splitcmd = ft_split_l(*(char **)cmd, splt, l_xp);
	if (!splitcmd || ft_free(*cmd, cmd) || !ft_memset(&l_xp, !0, sizeof(size_t)))
		return (errno);
	p = splitcmd;
	ft_printf("size:%d", (int)ft_strsplit_size(p));
	while (*(p++))
		ft_printf(":%s\n", *(p - 1));
	p = splitcmd;
	while (*(p++) && !errno && ft_memset(&tmp, 0, sizeof(char *)))//while (*p++) //&& ft_memset(expand, 1, sizeof(char)expand = **p; //FREE FT_JOIN
	{
		//if (ft_memset(&l_xp, **(p - 1) != 0, sizeof(size_t)) && !**(p - 1))
		//if ((l_xp != *(size_t *)ft_memset(&l_xp, **(p - 1), sizeof(size_t))) && !**(p - 1))
			//continue ;
		if (l_xp && cmd_sntzsl((t_vpp)(p - 1), splt + 2, ft_strlen(*(p - 1))))
			continue ;
		if (*(p - 1) && FT_MSET(&l_xp, **(p - 1), sizeof(size_t)) && !**(p - 1))
			continue ;
		tmp = FT_JOIN((char*)*cmd, *(p - 1));
		if (tmp || (*cmd && ft_free(*cmd, cmd)))
			*((char **)cmd) = tmp; //FT_JOIN
	}
	ft_strsplit_release(&splitcmd);
	return (errno);
}*/
typedef int (*t_expand)(void **, char *, size_t);
int void_sntzd(void **cmd, char *splt, size_t l_xp)
{
	(void)cmd;
	(void)splt;
	(void)l_xp;
	return (0);
}
t_expand proxy(char **cmd, size_t l_xp, char *split)
{
	//char	*key;
	(void)l_xp;
	if (!cmd || !split)
		return (void_sntzd);
	if ((*split != '$') || (!*cmd))
		return (void_sntzd);
	ft_printf("expand value of %s\n", *cmd);
	/*key = ft_strchr(*cmd, ' ');
	if ((size_t)*cmd == l_xp)
	{
	}*/
	
	return (void_sntzd);
	/*if (!l_xp && (*split != '$'))
		return (def_snt);
	if (*split == '$')
		return (cmd_sntzsl);
	return (cmd_sntzd);
	* */
}
/*
int cmd_sntzd(void **cmd, char *splt, size_t l_xp)
{
	char	**splitcmd;
	char	**p;
	char	*tmp;

	if (!cmd)
		return (-1);
	if ((cmd && *cmd == NULL) || (cmd && (**(char **)cmd) == '\0') || !*splt)
		return (errno);
	ft_striteri(*(char **)cmd, f_convert(*splt));
	splitcmd = ft_split_l(*(char **)cmd, splt, l_xp);
	if (!splitcmd || ft_free(*cmd, cmd) || !ft_memset(&l_xp, !0, sizeof(size_t)))
		return (errno);
	p = splitcmd;
	ft_printf("(%c)size:%d\n", *splt, (int)ft_strsplit_size(p));
	while (*(p++))
		ft_printf(":%s\n", *(p - 1));
	p = splitcmd;
	while (*(p++) && !errno && ft_memset(&tmp, 0, sizeof(char *)))//while (*p++) //&& ft_memset(expand, 1, sizeof(char)expand = **p; //FREE FT_JOIN
	{
		//if (ft_memset(&l_xp, **(p - 1) != 0, sizeof(size_t)) && !**(p - 1))
		//if ((l_xp != *(size_t *)ft_memset(&l_xp, **(p - 1), sizeof(size_t))) && !**(p - 1))//continue ;
		if (l_xp && cmd_sntzsl((t_vpp)(p - 1), splt + 2, ft_strlen(*(p - 1))))
		//if (l_xp && cmd_sntzsl((t_vpp)(p - 1), splt + 2, ft_strlen(*(p - 1))))
			continue ;
		if (*(p - 1) && FT_MSET(&l_xp, **(p - 1), sizeof(size_t)) && !**(p - 1))
			continue ;
		tmp = FT_JOIN((char*)*cmd, *(p - 1));
		if (tmp || (*cmd && ft_free(*cmd, cmd)))
			*((char **)cmd) = tmp; //FT_JOIN
	}
	ft_strsplit_release(&splitcmd);
	return (errno);
}
*/
char **envexpand(char ***ret, char **pre, char split, t_mini *x)
{
	char	**e;
	char	*val;
	char	**segm;
	
	if (!x || !ret)
		return (NULL);
	//ret = *segm;
	segm = *ret;
	while (*segm && !errno && (split == '$'))
	{
		if (**segm == 0)
			pre = segm;
		else if (pre && !ft_free(*pre, (void **)&*pre))
		{
			val = NULL;
			e = x->evm.find(&x->evm, *segm, &val);
			if (e && val)
				ft_strlcpy(*segm, *segm + (val - *e - 1), ft_strlen(*segm));
			else if (e && !val)
				ft_strlcpy(*segm, *segm + ft_strlen(*e), ft_strlen(*segm));
			*pre = FT_JOIN(val, NULL);
			pre = NULL;
		}
		segm++;
	}
	return (*ret);
}
			/*post = ft_strchr(*segment, ' ');
			post = ft_strchr(*segment, ' ');
			if (!post)
				post = *segment + ft_strlen(*segment);
			else if (ft_memset(post, 0, 1))
				post++;
			x->evm.find(&x->evm, *segment, &val);
			*pre = FT_JOIN(val, post);
			**segment = 0;
		* */
char	*ft_join_expand(char *s1, char *s2, size_t xp, char split)
{
	char	*result;

	if (!xp && ((split == '\'') || (split == '"')))
	{
		ft_striteri(s2, pipetoFF);
		/*if (s1 && (*s1 == '|'))
			*s2 = '\'';
		if (s2 && (*s2 == '|'))
		{
			*s2 = '\'';
			s2[ft_strlen(s2)] = '|';
		}*/
	}
	//	if (s2 && ((*s2 == '\'') || (*s2 == '"')))
			
	result = FT_JOIN(s1, s2);
	return (result); 
}
/*
 * convert single quote to 0			| double to 0					|$ to 0
 * split by 0							| split by 0					| split 0
 * flag interpret = 1					| flag interpret = 1			|i=1
 * for each split						| for each split				|foreach
 * 	if strlen_currentsplit is 0			| 	if 							|	if
 * 		interpret = !interpret			| 		i = !i					|		i=!i
 * 	if interpret						| 	if i						|	if i
 * 		rebuild currentsplit double quot|		rebuild with $expansion	|		delete and join by search
 *   
 * */					
int cmd_sntz(t_mini *x, void **cmd, char *splt, size_t l_xp)
{
	char	**splitcmd;
	char	**p;
	char	*tmp;

	if (!x || !cmd)
		return (-1);
	if ((cmd && *cmd == NULL) || (cmd && (**(char **)cmd) == '\0') || !*splt)
		return (errno);
	ft_striteri(*(char **)cmd, f_convert(*splt));
	splitcmd = ft_split_l(*(char **)cmd, splt, l_xp);
	if (!splitcmd || ft_free(*cmd, cmd) || !ft_memset(&l_xp, !0, sizeof(size_t)))
		return (errno);
	p = splitcmd;
	ft_printf("(%c)size:%d -- %u\n", *splt, (int)ft_strsplit_size(p), l_xp);
	while (*(p++))
		ft_printf(":%s\n", *(p - 1));
	p = envexpand(&splitcmd, NULL, *splt, x);
	while (*(p++) && !errno && ft_memset(&tmp, 0, sizeof(char *)))//while (*p++) //&& ft_memset(expand, 1, sizeof(char)expand = **p; //FREE FT_JOIN
	{
		if (!**(p - 1) && (*(size_t*)FT_MSET(&l_xp, !l_xp, sizeof(size_t))))
			continue ;
		if (l_xp && cmd_sntz(x, (t_vpp)(p - 1), splt + 2, ft_strlen(*(p - 1))))
			continue ;
char **p2 = splitcmd;
	ft_printf("(%c)size:%d -- %u\n", *splt, (int)ft_strsplit_size(p2), l_xp);
	while (*(p2++))
	{
		ft_printf(":%s\n", *(p2 - 1));
	}
		//if (!**(p - 1) && !FT_MSET(&l_xp, !l_xp, sizeof(size_t)) && !**(p - 1))
		//if (!**(p - 1) && !FT_MSET(&l_xp, !l_xp, sizeof(size_t)))
			//continue ;
		tmp = *cmd;
		*cmd = ft_join_expand(*(char**)cmd, *(p - 1), l_xp, *splt);
		ft_free(tmp, (void **)&tmp);
	}
	//return (errno + !!ft_strsplit_release(&splitcmd));
	return (errno + (ft_strsplit_release(&splitcmd) != NULL));
}

int sanitizes(t_mini *x, char **lne, char *splts, void(*add_his)(const char *))
{
	//char **p;
	
	if (!x || !lne || (lne && !*lne) || !splts)
		return (-1);
	if ((x->batchmode == 0) && add_his)
		(*add_his)((const char *)*lne);
	if ((cmd_sntz(x, (void **)lne, splts, ft_strlen(*lne)) != 0) && errno)
		perror("Sanitizes:");
	if (!*lne || (*lne && !ft_strlen(*lne)))
		return (errno);
	x->tkit = ft_countufsubstr(*lne, '|',  ft_strlen(*lne));
/*	lne = ft_split_c(*lne, '|', x->tkit);
	if (lne && !errno)
	{
		p = lne;
		while (*(p++))
		{
			ft_striteri(*(p - 1), FFtopipe_ws);
			ft_printf("%p>%s\n", p -1, *(p - 1));
		}
		ft_strsplit_release(&lne);
	}*/
	return (errno);
}

/*
 * Zero set the minishell structs
 * Prepare the token parser
 * cleanup will be on minishell destructor
 * enum tokenID
 * 	REDIRECT_STDIN = 0,
 *  REDIRECT_HEREDOC = 2,
 *  BUILTIN_ECHO = 4,
 *  BUILTIN_CD = 6,
 * ....
 * 	NOT_BUILTIN = 21,
 * 	REDIRECT_STDOUT = 22
 * REDIRECT_APPEND = 24
 * ....
 * 
 * char [][]tokens = {"<", "/dev/stdin" "<<",....}
 * <infile.txt
(gdb) print (x->tokenset[0])
$107 = 0x5555555653e0 "<<" --> <
(gdb) print (x->tokenset[1])
$108 = 0x555555565400 "" --> /dev/stdin -> infile.txt
(gdb) print (x->tokenset[2])
$109 = 0x555555565420 "<<" --> << here_doc
(gdb) print (x->tokenset[3])
$110 = 0x555555565440 ""
(gdb) print (x->tokenset[8])
$114 = 0x5555555654e0 "echo" hola mundo 1  2 3 4 asd asd 24 fsd sdf sdf 425 435
	tokenset[9] -> hola mundo 1  2 3 4 asd asd 24 fsd sdf sdf 425 435
(gdb) print (x->tokenset[10])
$115 = 0x555555565520 "cd"
* 	-> 0 o 1 parametro 
(gdb) print (x->tokenset[12])
$116 = 0x555555565560 "pwd"
* *	-> 0 parametro 
(gdb) print (x->tokenset[14])
$118 = 0x5555555655a0 "env"
* -> 0 parametro 
(gdb) print (x->tokenset[16])
$119 = 0x5555555655e0 "unset"
* -> 1 2 3 4 n parametro 
(gdb) print (x->tokenset[18])
$120 = 0x555555565620 "export"
* * -> 0 parametro 
(gdb) print (x->tokenset[20])
$121 = 0x555555565660 "exit"
	* * -> 0 parametro [21]
NO ES BUILTIN --> TODO LO ESCRITO
* 	[21] -> todo el comando...
(gdb) print (x->tokenset[22])
(gdb) print (x->tokenset[4])
$111 = 0x555555565460 ">>" --> > redirect outfile
(gdb) print (x->tokenset[5])
$112 = 0x555555565480 "" --> /dev/stdout
(gdb) print (x->tokenset[6])
$113 = 0x5555555654a0 ">>" --> >> redirect outfile no delete
(gdb) print (x->tokenset[7])
$113 = 0x5555555654a0 "" -> /dev/stdout
$123 = 0x0
* pipex.argv ->
*  [infile.txt |/dev/stdin]+ [builtns o loqueescribe] + [argumentos] + [outfile.txt|/dev/stdout]
 * */
t_mini *_zset(t_mini *x, int istty)
{
	size_t	toksz;
	char	*toks;
	char	sep[2];

	if (!x)
		exit(-1);
	ft_bzero(x, sizeof(t_minishell));
	ft_memset(x->evm.pd, -1, 3 * sizeof(int));
	ft_memset(x->wdm.pd, -1, 3 * sizeof(int));
	x->batchmode = istty - 1;
	x->splitsd = ft_strdup("\'\'$\'\"\'$\'");
	if (!x->splitsd)
		return (x);
	ft_striteri(x->splitsd + 1, single_noexptozero);
	//toks = ft_strdup("<<\'<<\'");
	//toks = ft_strdup("<<\'<<\'>>\'>>\'echo\'cd\'pwd\'env\'unset\'export\'exit\'");
	toks = ft_strdup("<\'<<\'>\'>>\'echo\'cd\'pwd\'env\'unset\'export\'exit\'");
	if (!toks)
		return (x);
	toksz = ft_strlen(toks);
	sep[0] = '\'';
	ft_striteri(toks, single_noexptozero);
	x->tokenset = ft_split_l(toks, sep, toksz);	//[REDIRECT]=<< [HEREDOC]=<< [REDIOUT]=>> [REDIOUT2]=>> ........ [x]=NULL
	ft_free(toks, (void **)&toks);
	return (x);
}

/*
 * Init and parses
 * if (!x->tokenset)
		return (_errno(&prs));
 * cleanup will be on minishell destructor
 * */
int prs(t_mini *x, int argc, char **argv)
{
	if (!x || (argc == 0) || !argv || errno)
		return (_errno(&prs));
	x->interactive = 1;
	return (_errno(&prs));
}
/*
int check_triplet_1(const char *in, char c)
{
	return ((*in++ == c) && ((*in && (*(in++) == c))) && ((*in && (*in == c))));
}
int redir_normalize_1(const char *in, char **out_norm, int *pf, int *c)
{
	*c = !FT_MSET(pf, -1, 3 * sizeof(int)) + FTPIPE(pf, 1, 0);
	while (in && out_norm && *in && !errno)
	{
		if (check_triplet_1(in, '<'))
				return (-1 + ft_pipeclose(pf));
		if ((*in == '<') && ((*(in + 1) && (*(in + 1) == '<'))) && in++)
			*c += ft_putstr_fd(" << ", pf[1]);
		else if (*in == '<')
			*c += ft_putstr_fd(" < ", pf[1]);
		if (check_triplet_1(in, '>'))
				return (-1 + ft_pipeclose(pf));
		if ((*in == '>') && ((*(in + 1) && (*(in + 1) == '>'))) && in++)
			*c += ft_putstr_fd(" >> ", pf[1]);
		else if (*in == '>')
			*c += ft_putstr_fd(" > ", pf[1]);
		if ((*in != '<') && (*in != '>'))
			*c += ft_putchar_fd(*in, pf[1]);
		in++;
	}
	if (!errno && ft_memset(out_norm, 0, sizeof(char *)))
		*out_norm = ft_calloc(*c + 1, sizeof(char));
	if (!*out_norm)
		return (-(*out_norm == NULL) + ft_pipeclose(pf));
	(*out_norm)[*c] = '\0';
	return (read(pf[0], *out_norm, *c) + ft_pipeclose(pf));
}
* */
/*
 * p->batchmode 
 *  >1 ignore multiple construction, DO NOT DESTROY!!
 * */
int	main(int ac, char **av, char **ep)
{
	t_mini	x;
	int		e;
	char	*l;

	e = prs(XCTOR(&x, ep, FTPIPE(_zset(&x, ft_tty())->evm.pd, 1, 0)), ac, av);
	while((e == 0) && !errno && ft_memset(&l, 0, sizeof(char *)))
	{
		if (ft_tty() == 0)
			l = readline("Minishell> ");
		else
			l = get_next_line(0);
		if (sanitizes(&x, &l, x.splitsd, add_history))
			break ;
			/*		
		* PIPEX: 
		*   <								>
		* 	infile "comando1 argumento1 argumento2" "cmd2 argumento1" .... outfile NOO
		* 	Un solo pipex, con el resultado de salida del hijo
		 * 	infile comando1 argumento1 argumento2 ... outfile NOO
		 * ME QUEDO CON EL PID DEL HIJO y tambien me quedo con el errno del hijo!!
		 * ----------------------
		 * <infile cat >outfile | <infile2 wc >outfile2 | 
		*    O
		*  here_doc separator comando outfile
		*  <<separator cat >outfile 
		* cuanto argumentos hay en un segmento de pipe? 
		* Ej:
		* 		ls 
		* LINE NUEVA!! para pipex-->   "/dev/stdin ls /dev/stdout"
		* 		bash !! marc echo sergio --> ERROR marc not found!!
		* 				-> PIPEX /dev/stdin marc echo sergio /dev/stdout
		* 		bash !! <marc echo sergio --> ERROR marc not found!!
		* 				-> PIPEX marc echo sergio /dev/stdout* 
		* 
		* 			marc? infile
		* 			echo
		* 			sergio outfile
		* 	/dev/stdin "marc\0echo" sergio -> 3 splits
		* 
		* 
		* */
		//char *out_norm;
		//int pfd[3];
		//int c;
		//if ((redir_normalize_1(l, &out_norm, pfd, &c) < 1) || errno)
			//break ;
		//ft_printf("Line norm: %s\n", out_norm);
		if (*l && (x.tkit && ft_pipex(&x, &l, x.tkit)))
		//if (*l && (x.tkit && ft_pipex(&x, &l, x.tkit)))
			break ;
		ft_printf("Line was: %s\n", l);
		ft_free(l, (void **)&l);
	}
	if (l)
		ft_free(l, (void **)&l);
	return (t_mini_dtor(&x));
}
/*char **exec_cmd;
			t = ft_strdup(splitsd);
			if (t && cmd_sanitze((void **)&line, t, ft_strlen(line) + 1) == 0)
			{
				exec_cmd = ft_split(line, ' ');
				if (!errno && exec_cmd && (ft_strsplit_size(exec_cmd) > 0))
					execve(exec_cmd[0], &exec_cmd[1], envp);
				ft_strsplit_release(&exec_cmd);
				ft_free(t, (void **)&t);
			}*/
			//sanitizes(&command, "\'\"");
			//ft_striteri(line, single_quotetozero);
			//sanear
			//sanitize(&line, linesize, '\'');
			//ft_split_l(line, '\0', linesize);
			//sanitize(line, linesize, '"');

			//piipex
				//pipex_minishell -> builtins o no
					//execv
			//ft_printf("%s", line);
			//test_sanitizer(line);			
			//free(line);
			/*
			result = sanitizer(line);
			char **result = (char*[]){"echo", "$USER", "no expand"};
			contar numeros resultados
			contar strlen de cada resultado
			join de todo --> "echo$USERno expand" --> pipex
			
			char **result = (char*[]){"echo ", "$USER ", "no expand"};
			contar numeros resultados
			contar strlen de cada resultado
			join de todo --> "echo $USER no expand" --> pipex
			*/
/*
 * 			//si solo hay una '
			char **result = (char*[]){"", NULL};
			//dos ''
			char **result = (char*[]){"", "", NULL};
			//<' '>
			char **result = (char*[]){"", " ", "", NULL};
			//<'">
			char **result = (char*[]){"", "\"", NULL};
			//<"'"> la prioridad de comillas simple gana
			char **result = (char*[]){"\"", "", "\"", NULL};
			//<'|> la prioridad de comillas simple gana
			char **result = (char*[]){"", "|", NULL};
			//...
			//<ec'ho' hola>
			char **result = (char*[]){"ec", "", "ho", "", "hola" NULL};
			//<'"ho"'la">
			char **result = (char*[]){"", "\"ho\"", "", "la"};
			//<"ho"la">
			char **result2 = (char*[]){"", "ho", "", "la"};
			
			char **result = (char*[]){"", "$USER", "no expand", NULL};

 * typedef struct s_cmdsanit
{
	char	*str;
	char	*shadow;
}	t_cmdsanitTEST;	

t_cmdsanitTEST result[] = {{"echo ", "11111"}, {"$USER ", "111111"}, {"no expand", "000000000"}};
t_cmdsanitTEST *iter;
iter = result;
	while(iter)
	{
		ft_printf("%s ---- Shadow:%s\n", iter->str, iter->shadow);
		iter++;
	}
*/
		
				
			/*char **dquotsplit = ft_split(line, '"');
			char **r, **s;
			r = dquotsplit;
			while(*r)
			{
				char **pipesplit = ft_split(line, '|');
				s = pipesplit;
				while(*s)
					ft_printf("%s\n", *s);
				r++;
			}
			ft_strsplit_release(&dquotsplit);			
			* */

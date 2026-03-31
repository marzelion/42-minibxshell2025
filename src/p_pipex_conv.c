/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pipex_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/02 14:13:19 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "libft/get_next_line_bonus.h"
#include "ft_printf.h"
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"
#include "minishellx.h"
#include "mx_utils.h"
#include "string_sanitizer.h"


/*
 * a=1 <hola command param1 param2 >bye a=1 a=1
 * LOCALS 1REDIRECTION COMMAND param param param 2REDIRECT TRASH!!!!
 * LOCALS HEREDOC COMMAND param param param 2REDIRECT TRASH!!!!
 * argv[0] = command!! <-SPLIT_n after LOCALS AND REDIRECTIONS
 * 
 * * a=1 <hola command param1 param2 >bye a=1 a=1
 * 0 omit assignations for now and remove!!
 * 1 command if not special<><<>>? OR echocdpwdexportunsetenvexit
 * 	exec
 * for each 
 * 	tag as visited
 * 	reconvert to pipex, if not on specials
 * 		if first, copy to argv[0]
 * 2 commands 
 * toks = ft_strdup("<<\'");
 * */
/*t_pipex *ft_pipex_launch(t_mini *x, char **lne, t_pipex *ppx)
{
	char	**p;
	
	lne = ft_split_c(*lne, ' ', ft_countufsubstr(*lne, ' ',  ft_strlen(*lne)));
	if (!lne)
		return (NULL);
	p = lne;
	while (*(p++) && !errno)
	{}
	ft_strsplit_release(&lne);
}
*/

t_pipex *ft_pipex_split_old(t_mini *x, char **lne, t_pipex *ppx)
{
	char	**p;
	char	*tmp;
	(void)tmp;
	(void)ppx;
	lne = ft_split_c(*lne, '|', ft_countufsubstr(*lne, '|',  ft_strlen(*lne)));
	if (!lne)
		return (NULL);
	p = lne;
	x->tkit = 0;
	x->tkstate = 0;
	while (*(p++) && !errno)
	{
		/*while (x->tokenset[x->tkit++] && !errno)
		{
			if (ft_strncmp(x->tokenset[x->tkit - 1], *(p -1), ft_strlen(x->tokenset[x->tkit - 1])) == 0)
			{
				if ((x->tkit - 1) == 0)
				{
					x->tkstate = x->tkit - 1;
					tmp = ppx->argv;
					ppx->argv = FT_JOIN(ppx->argv, "here_doc");
					if (tmp)
						ft_free(tmp, &tmp);
					if (!ppx->argv)
						break ;
					ppx->argc++;
				}
			}
		}*/
	}
	ft_strsplit_release(&lne);
	return (NULL);
}

typedef enum s_parsestate
{
	STATE_NORMAL = 0,
	STATE_COPY,
	STATE_NEXTSYMB,
	STATE_CHECK,
	STATE_MAX
} t_parsestate;

typedef int (*t_ppx_conv)(t_pipex *, char **);

/*
 * <infile?? < infile ?? 
 * >outfile?? > outfile??
 * << sep--> here_doc
 * >> --> añadir al fichero
 * ----------------------------
 * NO VOY A PONER  EL PIPEX -> pid_t=
 * echo
 * cd
 * pwd
 * export
 * env
 * unset
 * exit
 * -----------
 * |      ESTADO  \
 * |			   \
 * -----------	    \>
 * */
/*int echo_symb(int estado, t_pipex *p, char **pp)
{
	 FT_JOIN(linea_pipex, *pp); //"..... " + "echo"
								//"..... " + "argumento_1 de echo"
								//"..... " + "argumento_2 de echo"
								//"..... " + "argumento_3 de echo"
								....
	return(STATE_COPY);
}*/

/*
 * if (strcmp(*p, "echo")
 * {
 * 		ft_echo(line )
 * }
 * 
 * while
 *  GUARDARLO PARA NO LLMAR AL PIPEX!! 
 * 	{ESTADO_ECHO
 * 		ESTADO_CD
 * 	ESTADO_PWD
 * 	ESTADO_ ->ESTADO_STDOUT
 * 	}
 *  ESTADO_NOBUILTIN
 * ESTADO_STDOUT
 * 
 * 	strcmp(token[ECHO], linea)
 * {
 * 		estado = ft_echo(linea); -> ESTADO FINAL
 * }
 * 
 * enum estados
 * {
 *  ESTADO1 = 0,
 *  ESTADO2,
 *  ESTADO3,
 *  ESTADO_FINAL,
 * }
 * 
 * funcion_estado1(valor)
 * {
	 if (valor == NULL)
	    return (ESTADO_FINAL);
 *   return (1);
 * }
 * 
 * main (argv, argc)
 * 
 * estado inicial = ESTADO1;
 * while(estado <= estado final)
 * {
 * 	if(estado == ESTADO1)
 *  	estado+=funcion_estado1(argv[ESTADO1]);
	else if(estado == ESTADO2)
 * 		estado+=funcion_estado2(argv[ESTADO2]); 
 *  else if(estado == ESTADO3)
 * * 	estado+=funcion_estado3(argv[ESTADO3]); 
  *	else if(estado == ESTADO_FINAL)
 * 		break;* 
 * } * 
 * print (estado);
 * */
/*
int infile_symb(t_pipex *p, char **pp)
{
	if (!p || !pp || (pp && !*pp))
		return (STATE_MAX);
	//if (x->tkstate != 0)
		return (-1);
	FT_JOIN(linea_pipex, *pp); //"nombreprograma " + "infile.txt"
	//return (x->tkstate + 1);
	return (STATE_MAX);
	return (STATE_COPY);
	return (STATE_NORMAL);
}
*/
int void_symb(t_pipex *p, char **pp)
{
	(void)p;
	(void)pp;
	return (STATE_NORMAL);
}

int copy_symb(t_pipex *p, char **pp)
{
	(void)p;
	(void)pp;
	return (STATE_NORMAL);
}
/*
 * 0|2</dev/stdin ls OK, 1</dev/stdin ls ERROR
 * */
/*t_ppx_conv ft_lex(t_mini *x, char *symbol)
{
	//char	*f;
	int		r;
	
	if (!x || !symbol || (symbol && !*symbol))
		return (void_symb);
	if (x->tkstate == STATE_COPY)
		return (copy_symb);
	r = ft_strncmp(symbol, x->tokenset[x->tkit], ft_strlen(symbol) + 1);
	if (((x->tkit) == 0) && (r == -'<'))
		return (infile_symb);
	return (void_symb);
}*/

t_ppx_conv ft_lex(t_mini *x, char *symbol)
{
	//char	*f;
	int		r;
	
	if (!x || !symbol || (symbol && !*symbol))
		return (void_symb);
	r = ft_strncmp(x->tokenset[x->tkit], symbol, ft_strlen(x->tokenset[x->tkit]) + 1);
	if (((x->tkit) == 0) && ((r == '\0') || (r != '<')))
		return (void_symb);
	return (void_symb);
}

/*
 * if copy ok, change to normal, but for the next token!!
 * */
//typedef void *(*t_lexstatefunc)(t_mini *, char **, t_pipex *);
typedef void *(*t_lexstatefunc)(t_mini *, const char *, t_pipex *);


/*t_lexstatefunc lexstate_heredocredir(t_mini *x, char **token)
{
	if (!x || !token)
		return (NULL);
	//x->tkstate = x->tkit;
	if (**token == '\0')
		return (lexstate_inredir);
	if (**token == '<')
		**token = " ";
	x->tkit += 2;
	return (lexstate_normal);
}*/
void *lexstate_normal(t_mini *x, char **token, int cmp);

void *lexstate_inredir_1(t_mini *x, char **token, int cmp)
{
	char *tmp;
	
	if (!x || !token)
		return (NULL);
	if ((x->tkit == 0) && (cmp == -'<') && (x->tkit++) && (x->tkit++))
		return (lexstate_normal);
	else if ((x->tkit == 0) && (cmp == '\0') && (x->tkit++))
		return (lexstate_inredir_1);
	else if (x->tkit == 0)
		return (lexstate_inredir_1);
	tmp = x->buffer;
	if ((x->tkit == 0) && (x->tkit++) && (x->tkit++))
		x->buffer = FT_JOIN(x->buffer, *token);
	else if ((x->tkit == 1) && (x->tkit++))
	{
		**(token - 1) = ' ';
		x->buffer = FT_JOIN(x->buffer, *token);
	}
	else 
		x->buffer = FT_JOIN(x->buffer, "/dev/stdin ");
	if (tmp)
		ft_free(tmp, (void **)&tmp);
	return (lexstate_normal);
}

void *lexstate_normal(t_mini *x, char **token, int cmp)
{
	if (!x || !token)
		return (NULL);
	cmp = ft_strncmp(x->tokenset[x->tkit], *token, ft_strlen(x->tokenset[x->tkit]));
	if (x->tkit < 2)
		return (lexstate_inredir_1(x, token, cmp));
	return (lexstate_normal);
	/*if (((x->tkit < 0) && ((cmp == '\0') || (cmp != -'<'))))
		return (lexstate_inredir(x, token));
	else if ((x->tkit == 2) && (cmp == '\0'))
		return (lexstate_inredir(x, token));
	else if ((x->tkit > 4) && (*x->buffer == 0))
		return (lexstate_inredir(x, token));
		* */
		//ft_memset(*token, ' ', ft_strlen(x->tokenset[x->tkit]));
	/*cmp = ft_strncmp(x->tokenset[x->tkit], *p, ft_strlen(x->tokenset[x->tkit]))
	if (((x->tkit == 0) && ((cmp == '\0') || (cmp != -'<'))))
	{
		ft_memset(*l, ' ', ft_strlen(x->tokenset[x->tkit]));
		x->tkit++; //TOKEN_REDIRECT+1
		x->tkstate == STATE_COPY;
		lex_state = inredir_lex
	}*/
}
/*
typedef enum s_lexstate
{
	LEXSTATE_NORMAL = (const int64_t)&empty_lex,
	LEXSTATE_INRED = (const int64_t)&inredirstate_lex,
	LEXSTATE_MAX = (const int64_t)NULL
} t_lexstate;
*/

int ft_heredoc(t_mini *x, char **token)
{
	char *tmp;
	
	tmp = x->buffer;
	x->buffer = FT_JOIN(x->buffer, "here_doc ");
	ft_free(tmp, (void **)&tmp);
	if (!x->buffer)
		return (STATE_MAX);
	tmp = x->buffer;
	x->buffer = FT_JOIN(x->buffer, *token);
	ft_free(tmp, (void **)&tmp);
	if (!x->buffer)
		return (STATE_MAX);
	/*(cmp != -'<')
	">" "infile" token++;
	">infile" 
	token++; ">infile" ""
	
	x->tkstate = STATE_CHECK;*/
	return (STATE_CHECK);
}

int ft_echoanalyze(t_mini *x, char **token)
{
	char *tmp;
	
	tmp = x->buffer;
	x->buffer = FT_JOIN(x->buffer, *token); //"echo-nmarc"
	ft_free(tmp, (void **)&tmp);
	if (!x->buffer)
		return (STATE_MAX);
	tmp = x->buffer;
	x->buffer = FT_JOIN(x->buffer, *token); //"echo -n marc asd asd asd asd asd asd asd asd asd"
	ft_free(tmp, (void **)&tmp);
	if (!x->buffer)
		return (STATE_MAX);
	if (0)
		return (STATE_CHECK);
	return (STATE_NORMAL);
}

	
	/*char *buf;
	char *tmp;
	
	tmp = buf;
	cmp = ft_strncmp(x->tokenset[x->tkit], *p, ft_strlen(x->tokenset[x->tkit]))
	if ((x->tkit == 0) && (cmp != 0))
		buf = FT_JOIN(buf, line + 1)//"infile nombre_builtin argumento1 argumentos2 outfile"
		if (buf)
			ft_free(tmp))
	*/
	/*if ( (x->tkit == 0) && (cmp != -'<'))
		FT_JOIN(buf, line + 1) //NULL + "infile" = "infile"
	else if ( (x->tkit == 2) && (cmp != '\0'))
		algo para here_doc //NULL + "here_doc separa" = "here_doc separa"
	else if ( (x->tkit == 4) && (cmp != '\0'))
		algo para redirect stdout //"infile " + "outfile" = "infile outfile"
	else if ( (x->tkit == 6) && (cmp != '\0'))
		algo para redirect stdout sin overwirte	 //"infile " + "outfile2" = "infile outfile2"
	else if (((x->tkit > 8) && (x->tkit < 21)) && (cmp != '\0'))
		algo para echo, cd, pwd, env, export, unset exit //"infile outfile" + "nombre builtin" = "infile outfile nombre builtin"
	else if ( (x->tkit == 22) && (cmp != '\0'))
		algo para redirect_stdout
	else if ( (x->tkit == 24) && (cmp != '\0'))
		algo para redirect_stdout con overwrite*/


/*
 * tokenset[0]"<"tokenset[1]""tokenset[2]"<<"tokenset[3]""
 * vs 
 * [0]"<" or [0]"<infile" or [0]"<"[1]""[2]"infile"
 * */
int ft_pipex_split(t_mini *x, char **l, t_pipex *ppx, pid_t **pid)
{
	char			**p;
	t_lexstatefunc	lex_state;
	(void)lex_state;
	(void)p;
	if (!x || !l || !*l || (*l && !**l) || (x && !x->tokenset) || !ppx || !pid)
		return (-1 + t_pipex_dtor(ppx));
	l = ft_split_c(*l, ' ', ft_countufsubstr(*l, ' ',  ft_strlen(*l))); //echo marc [0]=echo [2]= marc [3]=NULL
	if (!l)
		return (t_pipex_dtor(ppx));
	p = l;
	x->tkstate = STATE_NORMAL;
	//lex_state = lexstate_normal;
	x->tkit = 0;
	while (*p && !errno)
	{		
		//lex_state = (*lex_state)(x, p, 0);
		p++;
		/*if (lex_state != lexstate_normal)
		{
			lex_state = (*lex_state)(x, p, 0);
		}
		else if (lex_state == lexstate_normal)
		{
			lex_state = (*lex_state)(x, p, 0);*/
			/*cmp = ft_strncmp(x->tokenset[x->tkit], *p, ft_strlen(x->tokenset[x->tkit]))
			if (((x->tkit == 0) && ((cmp == '\0') || (cmp != -'<'))))
			{
				ft_memset(*l, ' ', ft_strlen(x->tokenset[x->tkit]));
				x->tkit++; //TOKEN_REDIRECT+1
				x->tkstate == STATE_COPY;
				lex_state = inredir_lex
			}
			else if (((x->tkit == 1) && ((cmp == '\0') || (cmp != -'<'))))
			{
				ft_memset(*l, ' ', ft_strlen(x->tokenset[x->tkit]));
				x->tkit++; //TOKEN_REDIRECT+1
				x->tkstate == STATE_COPY;
				lex_state = heredoc_lex
			}*/
		/*}*/
		//p++;
		/*if (x->tkstate == STATE_NORMAL)
			x->tkstate = *(ft_lex(x, *p))(x, *p, *(p + 1));
			ft_lex(x, *p);
		else if (x->tkstate == STATE_CHECK)
			ft_check(x, &p);
		//comparo "<<\0" con "echo", que va a fallar -> < - e		//comparo "<<\0" con "<"\0, que va a fallar -> 0 - 0 		//comparo "<<\0" con "<<", que va a fallar -> OK, pero no
		//cmp = ft_strncmp(x->tokenset[x->tkit], *p, ft_strlen(x->tokenset[x->tkit]))
		//ft_lex(x, *p);		
		//ft_strncmp(x->tokenset[x->tkit], ft_strlen(x->tokenset[x->tkit]) + 1)
			//r = ft_strncmp(symbol, x->tokenset[x->tkit], ft_strlen(symbol) + 1);
	//if (((x->tkit) == 0) && (r == -'<'))
		if (x->tkstate == STATE_CHECK)
			p++;
		else
			x->tkit++;//p++;*/
	}	
 	/*pipex.argc = argc; // 6
	pipex.argv = argv; // char** [0]=./echo [1]=/dev/stdin [2]=echo [3]=marc [4]=/dev/stdout [5]=NULL
	pipex.envp = envp; x.envp
	pipex.run(&pipex, envp);*/
	/*while (*(p++) && !errno)
	{
		while (x->tokenset[x->tkit] && (x->tkstate <= STATE_COPY) && !errno)
		{
			x->tkstate =(*ft_lex(x, *(p - 1)))(ppx, p - 1);
			if ((x->tkstate == STATE_COPY) && (x->tkit != '\0'))
				break ;
	*/
				/*
				 * 	pipex.argc = argc; // 6
						    //echo marc   char** [0]=echo [1]=\0 [2]=marc [3]=NULL
					pipex.argv = argv; // char** [0]=./echo [1]=/dev/stdin [2]=echo [3]=marc [4]=/dev/stdout [5]=NULL
					pipex.envp = envp; x.envp
					pipex.run(&pipex, envp);
				 * 
				 * */
	/*
			x->tkit++;
		}//x->tkstate = *(ft_lex(x->tokenset[x->tkit++], p - 1))(ppx, p - 1);
	}*/
	if(ppx->child)
		**pid = ((t_procx *)ppx->child->content)->id;
	return (t_pipex_dtor(ppx) + !!ft_strsplit_release(&l));
}

int check_triplet(const char *in, char c)
{
	return ((*in++ == c) && ((*in && (*(in++) == c))) && ((*in && (*in == c))));
}

int redir_normalize(const char *in, char **out_norm, int *pf, int *c)
{
	*c = !FT_MSET(pf, -1, 3 * sizeof(int)) + FTPIPE(pf, 1, 0);
	while (in && out_norm && *in && !errno)
	{
		if (check_triplet(in, '<'))
				return (-1 + ft_pipeclose(pf));
		if ((*in == '<') && ((*(in + 1) && (*(in + 1) == '<'))) && in++)
			*c += ft_putstr_fd(" << ", pf[1]);
		else if (*in == '<')
			*c += ft_putstr_fd(" < ", pf[1]);
		if (check_triplet(in, '>'))
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
		*out_norm = ft_calloc(*c + 1 + 8, sizeof(char));
	if ((!*out_norm) || (*out_norm && (!ft_memcpy(*out_norm, "./pipex ", 8))))
		return (-(*out_norm == NULL) + ft_pipeclose(pf));
	(*out_norm)[*c] = '\0';
	return (read(pf[0], *out_norm, *c) + ft_pipeclose(pf));
}

typedef enum e_state {
    ST_ANY = 0,
    ST_EXPECT_IN,
    ST_EXPECT_HEREDOC,
    ST_EXPECT_OUT
} t_state;

void *lexstate_any(t_mini *x, const char *t, t_pipex *ppx);
void *lexstate_inredir(t_mini *x, const char *t, t_pipex *ppx);
void *lexstate_heredoc(t_mini *x, const char *t, t_pipex *ppx);
void *lexstate_outredir(t_mini *x, const char *winn_t, t_pipex *ppx);
void *lexstate_appndredir(t_mini *x, const char *winn_t, t_pipex *ppx);
//void *lexstate_inredir(t_mini *x, const char *t, int *pf, int *c);

int streq(const char *a, const char *b)
{
	return (ft_strncmp(a, b, ft_strlen(b) + 1) == 0);
}

int is_op_token(const char *t)
{
	return (streq(t, "<") || streq(t, "<<") || streq(t, ">") || streq(t, ">>"));
}

// strdup y free anterior si existe
void ft_strreplace(char **dst, const char *src)
{
	char *tmp;

	**dst = '\0';
	tmp = ft_strdup(src);
	if (!tmp || errno)
		return ;
	ft_free(*dst, (void **)dst);
	*dst = tmp;
}

void *lexstate_any(t_mini *x, const char *t, t_pipex *ppx)
{
	char *tmp;

	(void)ppx;
	if (streq(t, "<"))
		return lexstate_inredir;
	else if (streq(t, "<<"))
		return lexstate_heredoc;
	else if (streq(t, ">"))
		return lexstate_outredir;
	else if (streq(t, ">>"))
		return lexstate_appndredir;
	//*c = ft_putstr_fd((char *)t, pf[1]);
	tmp = x->cmd_conv;
	x->cmd_conv = FT_JOIN(x->cmd_conv, t);
	ft_free(tmp, (void **)&tmp);
	if (!x->cmd_conv)
		return (NULL);
	tmp = x->cmd_conv;
	x->cmd_conv = FT_JOIN(x->cmd_conv, " ");
	ft_free(tmp, (void **)&tmp);
	if (!x->cmd_conv)
		return (NULL);
	return (lexstate_any);
}
/*	x->tkit = 8;
	while(x->tkit < 22)
	{
		if (streq(t, x->tokenset[x->tkit]))
		{
			//if (x->tokenset[x->tkit] == 0)
				//x->tokenset[x->tkit]++;
			break ;
		}
		x->tkit += 2;
	}
*/

void *lexstate_appndredir(t_mini *x, const char *winn_t, t_pipex *ppx)
{
	char **tmp;
	int mode;

	tmp = NULL;
    if (*x->tokenset[5] != '\0')
    {
        mode = O_WRONLY | O_CREAT | O_APPEND;
        ppx->outfilefd = filex_prp(x->tokenset[5], &mode, 0644, NULL);
		ppx->error = close(pipefd[0]);
		tmp = &x->tokenset[5];
    }
    else if (*x->tokenset[7] != '\0')
    {
        mode = O_WRONLY | O_CREAT | O_APPEND;
        ppx->outfilefd = filex_prp(x->tokenset[7], &mode, 0644, NULL);
        ppx->error = close(fd);
		tmp = &x->tokenset[7];
    }	
	x->tokenset[7] = ft_strdup(winn_t);
	if (tmp)
    	ft_free(tmp, (void **)&tmp);
	if (!x->tokenset[5])
		return (NULL);
	return (lexstate_any);
}

void *lexstate_outredir(t_mini *x, const char *winn_t, t_pipex *ppx)
{
	char **tmp;
	int mode;

	tmp = NULL;
    if (*x->tokenset[7] != '\0')
    {
        mode = O_WRONLY | O_CREAT | O_APPEND;
        ppx->outfilefd = filex_prp(x->tokenset[7], &mode, 0644, NULL);
        ppx->error = close(fd);
		tmp = &x->tokenset[5];
    }
    else if (*x->tokenset[5] != '\0')
    {
        mode = O_WRONLY | O_CREAT | O_TRUNC;//permiso para escribir, crear o truncar
        ppx->outfilefd = filex_prp(x->tokenset[5], &mode, 0644, NULL);
		ppx->error = close(pipefd[0]);
		tmp = &x->tokenset[7];
    }
	x->tokenset[7] = ft_strdup(winn_t);
	if (tmp)
    	ft_free(tmp, (void **)&tmp);
	if (!x->tokenset[7])
		return (NULL);	
	return (lexstate_any);
}

void *lexstate_heredoc(t_mini *x, const char *winn_t, t_pipex *ppx)
{
	(void)x;
	(void)winn_t;
	(void)ppx;
	return (lexstate_any);
}

void *lexstate_inredir(t_mini *x, const char *winn_t, t_pipex *ppx)
{
	int		pipefd[2];
	t_procx	hdoc_px;

	if (is_op_token(winn_t) && (errno++) && ft_perror(++errno, "inredir", 0, 0))
		return (NULL);
	if ((*x->tokenset[3] != '\0') && ft_memset(&hdoc_px, 0, sizeof(hdoc_px)))
	{
		if (ft_perror(pipe(pipefd), _W, 1, 0) )
			return (NULL);
		ppx->ppfd = pipefd;
		ppx->lim = x->tokenset[3];
		if (t_pipex_redirect_parent(ppx, &hdoc_px) && errno)
			return (NULL);
		ppx->error = close(pipefd[0]) + close(pipefd[1]);
		ppx->ppfd = NULL;
		ppx->infilefd = -1;
	}
	if (*x->tokenset[1] != '\0')
	{
		pipefd[1] = O_RDONLY;
		pipefd[0] = filex_prp(x->tokenset[1], (pipefd + 1), 0, NULL);
		ppx->error = (pipefd[0] == -1) + (pipefd[1] < 0) + close(pipefd[0]);
	}
	ft_strreplace(&(x->tokenset[1]), winn_t);
	return (lexstate_any);
}
/*	char *tmp;
	
	if (!x || !token)
		return (NULL);
	if ((x->tkit == 0) && (cmp == -'<') && (x->tkit++) && (x->tkit++))
		return (lexstate_normal);
	else if ((x->tkit == 0) && (cmp == '\0') && (x->tkit++))
		return (lexstate_inredir);
	else if (x->tkit == 0)
		return (lexstate_inredir);
	tmp = x->buffer;
	if ((x->tkit == 0) && (x->tkit++) && (x->tkit++))
		x->buffer = FT_JOIN(x->buffer, *token);
	else if ((x->tkit == 1) && (x->tkit++))
	{
		**(token - 1) = ' ';
		x->buffer = FT_JOIN(x->buffer, *token);
	}
	else 
		x->buffer = FT_JOIN(x->buffer, "/dev/stdin ");
	if (tmp)
		ft_free(tmp, (void **)&tmp);
	return (lexstate_normal);*/


void ft_pipex_cmdconv(t_mini *x, char **tokv, t_pipex *ppx)
{
	const char		*t;
	t_lexstatefunc	st;	

	st = lexstate_any;
	if (x->cmd_conv)
		ft_free(x->cmd_conv, (void **)&x->cmd_conv);
	x->cmd_conv = ft_strdup("./pipex ");
	if (!x->cmd_conv)
		return ;
	while(*(tokv++) && !errno)
	{
		t = *(tokv - 1);
		st = (*st)(x, t, ppx);
		/*if (st == lexstate_any && !is_op_token(t))
        {
            tmp = x->cmd_conv;
            x->cmd_conv = FT_JOIN(x->cmd_conv, t);
            ft_free(tmp, (void **)&tmp);

            tmp = x->cmd_conv;
            x->cmd_conv = FT_JOIN(x->cmd_conv, " ");
            ft_free(tmp, (void **)&tmp);
        }*/		
		/*if (st == ST_ANY)
		{ //"<outfile <outfile => outfile outfile ..."
			if (streq(t, "<"))
				return lexstate_inredir;
			else if (streq(t, "<<"))
				return lexstate_heredoc;
			else if (streq(t, ">"))
				return lexstate_outredir;
			else if (streq(t, ">>"))
				return lexstate_outappend;
		}*/
		/*st = ST_EXPECT_IN;
		else if (st == ST_EXPECT_IN)
			st = ST_ANY;
		else if (st == ST_EXPECT_HEREDOC)
			st = ST_ANY;
		else if (st == ST_EXPECT_OUT)
			st = ST_ANY;
		else if (st == ST_EXPECT_OUTAPPEND)
			st = ST_ANY;			*/
	}
}
int ft_pipex_split_1(t_mini *x, char **l, t_pipex *ppx, pid_t **pid)
{
	int pfd[3];
	int c;	//char **p;
	char *out_norm;
	
	if (!x || !l || !*l || (*l && !**l) || (x && !x->tokenset) || !ppx || !pid)
		return (-1 + t_pipex_dtor(ppx));
	if (redir_normalize(*l, &out_norm, pfd, &c) < 1)
		return (t_pipex_dtor(ppx));
	ft_printf("Line norm: %s\n", out_norm);
	l = ft_split_c(out_norm, ' ', ft_countufsubstr(out_norm, ' ',  ft_strlen(out_norm))); //echo marc [0]=echo [2]= marc [3]=NULL
	if (!l)
		return (t_pipex_dtor(ppx) + !ft_free(out_norm, (void **)&out_norm) - 1);
	if (l && !errno)
	{
		ft_pipex_cmdconv(x, l, ppx);
		//c = FTPIPE(pfd, 1, 0);

		/*p = l;
		while (*(p++))
		{
			ft_striteri(*(p - 1), FFtopipe_ws);
			ft_printf("%p~%s\n", p -1, *(p - 1));
		}*/
	}
	ft_putendl(x->cmd_conv);
	ft_free(out_norm, (void **)&out_norm);
	return (t_pipex_dtor(ppx) + (ft_strsplit_release(&l) != NULL));
}

int ft_pipex(t_mini *x, char **l, int pipexsz)
{
	pid_t	*pxs;
	t_pipex	ppx;
	char	**p;
	(void)ppx;
	if (!x || !l || !*l || (*l && !**l) || !pipexsz || (x && !x->tokenset))
		return (-1);
	pxs = ft_calloc(pipexsz, sizeof(pid_t));
	if (!pxs)
		return (errno);
	l = ft_split_c(*l, '|', pipexsz); //echo | marc --> [0]=echo [1]=\0 [2]= marc [3]=NULL
	if (!l)
		return (errno + !!ft_free(pxs, (void **)&pxs));
	p = l;
	//pxs += pipexsz;
	//pxs = pipexsz;
	//while ((pxs--) && *(p++) && !errno)
	while (*(p++) && !errno)
	{
		//ft_striteri(*(p - 1), FFtopipe_ws); //"|"->"0x7f"
		x->last_px = ft_pipex_split_1(x, p - 1, t_pipex_ctor(&ppx), &pxs);
		if (x->last_px)
			break ;
	}
	return (errno + !!ft_strsplit_release(&l) + !!ft_free(pxs, (void **)&pxs));
}
/*	if (ft_pipex_split(x, lne, &pipex))
	{	
		return (t_pipex_dtor(&pipex));
	}
	{
		{
			
			ft_printf("%p>%s\n", p -1, *(p - 1));
			pipex.argc = ft_strsplit_size(*(p - 1));
			pipex.argv = *(p - 1);
			pipex.envp = x->evm.envp;
			pipex.run(&pipex, x->evm.envp);
		}
	}
	return (t_pipex_dtor(&pipex));
* */

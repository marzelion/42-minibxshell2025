
#include "libft.h"
#include "get_next_line_bonus.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

typedef char* (*t_prompt)(char *);

char	*ft_prompt(char *val)
{
	if (!val || (val && (*val == '\0')))
		return (0);
	if (ft_putstr_fd(val, 1) == ((size_t)-1))
		perror(NULL);
	return (0);
}

/*
 * ft_putstr_fd(prompt, 1);
 * */
char	*getreadline(char **line, t_prompt p)
{
	if (!line)
		return (NULL);
	if (isatty(0))
		*line = readline(p(*line));//shell->prompt = readline(shell->terminal_prompt);	if (!*line)	perror(NULL);
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
}

typedef	struct s_mlinectxt
{
	char	*acc;
	//int		is_continuation;
	char	*ct;
	int		line_count;
	int		(*realloc)(struct s_mlinectxt *, char **, char *);
}	t_mlinectxt;

int t_mlnctx_realloc(t_mlinectxt *p, char **l, char *basebuf)
{
	if (!p || !l || (l && !(*l)))
		return (0);
	p->ct = FT_JOIN(p->acc, *l);
	ft_free(*l, (t_vpp)l);
	if ( p->ct && p->acc && (p->acc != basebuf))
		ft_free(p->acc, (t_vpp) & p->acc);
	if (!p->ct)
		return (1);
	p->acc = p->ct;
	
//p->ct = FT_JOIN(p->acc, *l) + !ft_free(*l, (t_vpp)l);
		//if (!p->ct || ((p->acc != ps1) && !ft_free(p->acc, (t_vpp) & p->acc)))
			//return (p->acc);
	return (0);
}
/*
 ft_free(*l, (t_vpp)l) = ft_memcpy(p->cont, FT_JOIN(p->acc, *l);
if (ft_memcpy(p->cont, FT_JOIN(p->acc, *l), 0) == ft_free(*l, (t_vpp)l))
return (p->acc);//p->is_cont = FT_JOIN(p->acc, *l), ft_free(*l, (t_vpp)l), 0);
 * */
char	*handle_multiline_input(t_mlinectxt *p, char **l, char *ps1, char *ps2)
{
	char	*s;

	if (!l || (l && (*l)))
		return (NULL);
	s = ps2;
	*l = ps1;
	while ((s != ps1) && getreadline(l, ft_prompt) && (**l != '\0'))
	{
		s = ft_strchr(*l, '\0');
		if (!isatty(0))
			s = ft_strchr(*l, '\n');
		if (s && (s != *l) && (*(s - 1) == '\\'))
		{
			*(s - 1) = '\0';
			s = ps2;
		}
		else
			s = ps1;
		if (p->realloc(p, l, ps1))
			return (p->acc);
		*l = s;
	}
	return (*l);
}

/*	pc->is_continuation = ps1;
	while ((getreadline(l, pc->is_continuation) != NULL))
	{
		s = ft_strchr(*l, '\\');
		if (s && (*(s + 1) == '\0'))
		{
			*s = '\0';
			pc->is_continuation = ps2;
		}
		else
			pc->is_continuation = ps1;
		s = pc->accumulated_input;
		pc->accumulated_input = ft_strjoin(pc->accumulated_input, *l);
		if(s)
		{	
			free(s);
			s = NULL;
		}
		free(*l);
		*l=NULL;
		//if (pc->is_continuation == ps1)
			//add_history(pc->accumulated_input);
	}
* */
int	main(int argc, char **argv)
{
	t_mlinectxt	ctx;
	char		*input;
	char		*ps1 = ">";

	(void) argc;
	(void) argv;
	input = NULL;
	ctx.acc = ps1;
	ctx.ct = NULL;
	ctx.line_count = 0;
	ctx.realloc = t_mlnctx_realloc;

	while ((handle_multiline_input(&ctx, &input, ps1, "$")) != NULL)
	{
		if (input && (input != ps1))
			ft_free(input, (t_vpp)&input);
		input = NULL;
		if (0 && (ctx.acc == ps1))
			break;
		if (isatty(0))
			printf("%s\n", ctx.acc + ft_strlen(ps1));
		else if (ctx.acc !=ps1)
			printf("%s", ctx.acc+ ft_strlen(ps1));
		if (ctx.acc && (ctx.acc != ps1))
		{
		//	if (*ctx.acc == '\0')
			//	break ;
			ft_free(ctx.acc, (t_vpp)&ctx.acc);
		}
		ctx.ct = NULL;
		ctx.acc = ps1;
	}
	if (input && (input != ps1))
		ft_free(input, (t_vpp)&input);
	if (ctx.acc &&(ctx.acc != ps1))
	{
		if (isatty(0))
			printf("%s\n", ctx.acc + ft_strlen(ps1));
		else
			printf("\n%s", ctx.acc + ft_strlen(ps1));
	}
	ctx.ct = NULL;
	if (ctx.acc &&(ctx.acc != ps1))
		ft_free(ctx.acc, (t_vpp) & ctx.acc);
	return (0);
}

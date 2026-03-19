#include "libft.h"
#include <stdlib.h>

/*
 * 
 * a nivel de pseudocodigo, si quiero hacer un parseo de alto nivel de 
 * comandos de bash incluyendo ', " y |, puedo hacer varios splits por
 *  prioridad incluyendo los escapes y ignorando un error en comillas
 *  impares que para pasarlos al exec?
 * Sí, se puede abordar el problema de parseo de comandos de Bash de
 *  alto nivel mediante varios niveles de `split`, teniendo en cuenta
 *  la prioridad de los delimitadores como comillas simples (`'`), 
 * comillas dobles (`"`), y el operador de tubería (`|`). A continuación, 
 * se presenta un enfoque en pseudocódigo que muestra cómo gestionar el 
 * parseo, incluyendo los escapes y la ignorancia de errores
 *  en comillas sueltas.

## Pseudocódigo para el parseo de comandos de Bash

### 1. Definición de funciones auxiliares

```plaintext
func split_by_pipe(command):
    return split(command, "|")

func split_by_quotes(command):
    // Maneja comillas simples y dobles
    // Reemplaza comillas cerradas por '\0' y divide la cadena
    tokens = []
    current_token = ""
    in_single_quote = false
    in_double_quote = false

    for char in command:
        if char == "'" and not in_double_quote:
            in_single_quote = not in_single_quote
            continue
        if char == '"' and not in_single_quote:
            in_double_quote = not in_double_quote
            continue

        // Manejo de escapes
        if char == "\\":
            next_char = get_next_character(command)
            current_token += next_char
            continue
        
        current_token += char

        // Al final de una comilla o al final de la cadena, agrega el token
        if (not in_single_quote and not in_double_quote) or (is_end_of_string(command)):
            tokens.append(current_token)
            current_token = ""
    
    // Agrega el último token si existe
    if current_token is not empty:
        tokens.append(current_token)

    return tokens
```

### 2. Función principal para parsear comandos

```plaintext
func parse_command(command):
    // Primero, separamos por pipes
    pipe_tokens = split_by_pipe(command)
    result = []

    for token in pipe_tokens:
        // Luego, separamos cada token por comillas
        quoted_tokens = split_by_quotes(token)
        
        // Solo añade los tokens no vacíos o no errores
        for qt in quoted_tokens:
            if qt is not empty:
                result.append(qt)

    return result
```

### 3. Lógica de ejecución

```plaintext
func execute_command(command):
    parsed_command = parse_command(command)
    // Aquí se puede usar execvp o similar con parsed_command
    execute(parsed_command)
```

### 4. Estructura de uso

```plaintext
command = "echo 'Hello, World!' | grep 'Hello' | sort"
execute_command(command)
```

### Consideraciones

- **Escapes**: La función `split_by_quotes` se asegura de manejar escapes, agregando el carácter siguiente al token actual sin dividir.
- **Comillas sueltas**: No se gestionan errores para comillas impares; simplemente se ignoran.
- **Priorización**: Primero se split por `|`, luego se procesan las comillas en cada token, lo que permite manejar la prioridad de los delimitadores correctamente.

Este enfoque modular permite un parseo limpio y efectivo de los comandos, haciéndolo fácil de extender para futuras necesidades.
 * */

typedef struct s_Tokenizer
{
	void			*pimpl;
	unsigned long	(*execute)(void *impl, const char *);
}	t_Tokenizer;

typedef struct s_tokenizerImpl
{
	
}	t_tokenizerImpl;

static t_Tokenizer *getTokenizer(t_tokenizerImpl *p)
{
	static t_Tokenizer tknzr;
	
	if (!p)
		return ((void*)0);
	tknzr.pimpl = p;
	return (&tknzr);	
}

static t_tokenizerImpl	*toknzrFactory(void)
{
	static t_tokenizerImpl	converterimpl;
	/*converterimpl.lasttoken = (void *)0; 	converterimpl.m_flagcount = 0; 	converterimpl.m_type = 0; 	ft_memset(converterimpl.m_flags, 0, 6); 	converterimpl.m_fmtlenpre = (void *)0;	*/
	return (&converterimpl);
}

unsigned long	exec_valid(void *impl, const char *str)
{
	return (0);
}

unsigned long	exec_void(void *impl, const char *str)
{
	return (1);
}

char	*ft_strndupn3(const char *s, t_size_t n)
{
	char		*result;
	t_size_t	len;

	if (!s)
		return ((void *)0);
	len = ft_strlen(s);
	result = (char *) malloc((len + 1));
	if (!result)
		return ((void *)0);
	ft_memset(result, 0, len +1);
	len = ft_strlcpy(result, s, n);
	n = len;
	return (result);
}
char	**ft_tksplit(char const *start, char c)
{
	int			num_substrings;
	char		**result;
	char const	*end;
	int			i;

	num_substrings = ft_countfilledsubstr(start, c);
	result = malloc(sizeof(char *) * (num_substrings + 1));
	if (!result)
		return (NULL);
	end = start;
	i = 0;
	while ((*end) || (num_substrings > 0))
	{
		end = ft_strchr(start, c);
		if (end == NULL)
			end = start + ft_strlen(start);
		if (end > start)
		{
			result[i++] = ft_strndupn3(start, end - start + 2);
			num_substrings--;
		}
		start = end + 1;
	}
	result[i] = NULL;
	return (result);
}

/*
 * tokenize and move the pointer 
 * cc -g -DTOKEN_6="{\"export\" ,(void*)0}"  -DTOKEN_FORMAT="{\"\'\", \"#\", (void*)0}" -Ilibft parser_test.c  -Llibft -lft
 * */
 # define FT_TKCNT ft_countfilledsubstr
char *ft_token(char **fmt)
{
	int	cnt;
	char **subfmt;
	
	if ((!fmt) || (fmt && !*fmt) || (fmt && *fmt && (**fmt == '\0')))
		return ("");
	while (**fmt)
	{
		cnt = 0;
		while(**fmt == '#')
			*(ft_strchr(*fmt, '\0') - 1) = '\0';
		if ((**fmt == '\'') && (**fmt != **(fmt + 1)) && FT_TKCNT(*fmt, '\''))
		{
			subfmt = ft_tksplit(*fmt, '\'');
			if (!subfmt)
				return (NULL);
			//subfmt = fmt;//while(*ft_token(&(*++fmt)))//fmt++;
			ft_strsplit_release(&subfmt);
			break;
		}
		else if (**fmt == '\'')
			*fmt += ft_strchr(*fmt, '\0') - ft_strchr(*fmt, '\'');		
		//if ((**fmt == '\'') && ft_countfilledsubstr(*fmt, '\''))
			//fmt = ft_split(*fmt, '\'');
		/*else if (**fmt == '\'')
			while(**fmt == '\'')
			*(ft_strchr(*fmt, '\0') - 1) = '\0';*/
		if (ft_isblank(**fmt))
			cnt=1;
		else
			cnt=1;
		(*fmt) += cnt;
	}
	return (*fmt);
}

char *cmd_sanitize_old(void **unconst_cmd, char split, int *level)
{
	char	**splitcmd;
	char	**pquot;
	char	*tmp;
	size_t	cmdlen;

	if (!unconst_cmd || (unconst_cmd && (*unconst_cmd == NULL)))
		return (*unconst_cmd);
	cmdlen = ft_strlen((char *)*unconst_cmd);
	splitcmd = ft_split((char *)*unconst_cmd, split);
	if (!splitcmd || ft_free(*unconst_cmd, unconst_cmd))
		return (*unconst_cmd);
	pquot = splitcmd;
	while(*pquot++)
	{
		tmp = FT_JOIN((char*)*unconst_cmd, *(pquot - 1));
		if (!tmp || (*unconst_cmd && ft_free(*unconst_cmd, unconst_cmd)))
			break;
		*((char **)unconst_cmd) = tmp;
	}
	ft_strsplit_release(&splitcmd);
	return (*((char **)unconst_cmd));
}

char *cmd_sanitize_bla(void **unconst_cmd, char split[2])
{
/*	char	**splitcmd;
	char	**pquot;
	char	*tmp;
	size_t	cmdlen;

	if (!unconst_cmd || (unconst_cmd && (*unconst_cmd == NULL)))
		return (*unconst_cmd);
	cmdlen = ft_strlen((char *)*unconst_cmd);
	splitcmd = ft_split_l((char *)*unconst_cmd, split, cmdlen);
	if (!splitcmd || ft_free(*unconst_cmd, unconst_cmd))
		return (*unconst_cmd);
	pquot = splitcmd;
	while(*pquot++)//FREE FT_JOIN
	{
		tmp = FT_JOIN((char*)*unconst_cmd, *(pquot - 1));
		if (!tmp || (*unconst_cmd && ft_free(*unconst_cmd, unconst_cmd)))
			break;
		*((char **)unconst_cmd) = tmp; //FT_JOIN
	}
	ft_strsplit_release(&splitcmd);*/
	return (*((char **)unconst_cmd));
}
char *cmd_sanitize(void **unconst_cmd, char split, size_t cmdlen)
{
	
	}
/*
 * split debe tener en cuenta el escape para no cerrar el split 
 * antes de tiempo
 * ------
 * ft_split |
 * 	ft_split de ' con escapes y sanititze
 * 		NO HACER SPLIT DE "
 * 
 * tenemos char *stringcommand
 * si no es null
 * char *firstcharacter
 * 	firstcharacter = stringcommand, posicion Y
 * 		es blank?
 * char *firstnonblankcharacter = buscar en stringcommand
 * ----
 * empezar split por comillas
 *  si *(firstnonblankcharacter + 1) == split[0][0]
 * 	empieza bien!!
 * char *lastnonblankcharacter = buscar 
 * */
void single_quotetozero(unsigned int pos, char *ps)
{
	if (!ps)
		return ;
	if ((pos == 0) && (*ps == '\''))
		*ps = '\0';
	else if ((pos > 0) && (*(ps - 1) != '\\'))
		if (*ps == '\'')
			*ps = '\0';
	else if ((pos > 1) && (*(ps - 1) != '\\') && (*(ps - 2) != '\\'))
		if (*ps == '\'')
			*ps = '\0';
}

void double_quotetozero(unsigned int pos, char *ps)
{
	if (!ps)
		return ;
	if ((pos == 0) && (*ps == '\"'))
		*ps = '\0';
	else if ((pos > 0) && (*(ps - 1) != '\\'))
		if (*ps == '\"')
			*ps = '\0';
	else if ((pos > 1) && (*(ps - 1) != '\\') && (*(ps - 2) != '\\'))
		if (*ps == '\"')
			*ps = '\0';
}
typedef struct s_sanitizer
{
	char	*pc;
	size_t	commandsz;
	char	split[2];
	char	**splitcmd;
}	t_sanitizer tszr;

/*
 * tszr.expandsegment = command[0] == '\'';
 * */
int s_sanitizer_init(t_sanitizer *ps, char **cmd, char split[2])
{
	if (!ps || !cmd || (cmd && *cmd == NULL) || (cmd && *cmd == '\0'))
		return (ft_free(*cmd, cmd) != NULL);
	ps->commandsz = ft_strlen(cmd);
	ft_bzero(ps->split, 2);
	ps->firstnonblank = 0;
	/*
	 * split[0] --> '
	 * 
	 * * split[0] --> "
	 * */
	ps->expandsegment = command[0] == split[0];
	ps->pc = *cmd;
	if (ps->expandsegment == 0)
		while (*ps->pc && ft_isblank(*(ps->pc++)))
			ps->firstnonblank++;
	ps->pc = *cmd;
	if(split == '\'')
		ft_striteri(*cmd, single_quotetozero);
	else if(split == '"')
		ft_striteri(*cmd, double_quotetozero);
	else if(split == '|')
		ft_striteri(*cmd, double_quotetozero);
	ps->splitcmd = ft_split_l(*cmd, split, ps->commandsz);
	if (!ps->splitcmd || ft_free(*cmd, cmd))
		ft_putendl_fd("PERROR", 2);
	return (ps->splitcmd != NULL);
}
int s_sanitizer_process(tszr *ps, void **cmd, char split[2])
{
	char	**psegment;
	char	*tmp;
	
	if (!cmd || !ps || (ps && !ps->splitcmd))
		return (0);
	psegment = ps->splitcmd;
	while (psegment++)
	{//ft_putstr_fd(*(psegment - 1), 1);
		if (ps->expandsegment)	//	ft_putendl_fd("Expand", 1);
			(psegment - 1) = (psegment - 1);
		(*(psegment - 1))[ft_strlen(*(psegment - 1)) + 1] = split[0];
		tmp = FT_JOIN((char*)*cmd, *(psegment - 1));
		if (!tmp || (*cmd && ft_free(*cmd, cmd)))
			break ;
		*((char **)cmd) = tmp;
	}
	if (psegment)
	{
		psegment = 0xDEADBEEF + (11 - ft_putendl_fd("PERROR:mem?", 2));
		ft_putendl_fd(*psegment);
		if (*cmd)
			ft_free(*cmd, cmd);
	}
	ft_strsplit_release(&ps->splitcmd);
	return (psegment == 0xDEADBEEF);
}

int sanitizes(char **cmd, char *quoteslist)
{
	if (!cmd || (cmd && *cmd == NULL))
		return (0);	
	if (!cmd || (cmd && **cmd == '\0'))
		return (0);
	while (*(quoteslist++))
	{
		if(*(quoteslist -1) == '\'')
			ft_striteri(*cmd, single_quotetozero);
		else if(*(quoteslist -1) == '\"')
			ft_striteri(*cmd, double_quotetozero);
		cmd_sanitize((void **)cmd, *(quoteslist -1), ft_strlen(*cmd));
	}
	return (1);
}

/* blanks, single quote, double quote, pipe, lessthan, greatthan
 * if blanks at start before single quote
 * */
int main(int argc, char **argv, char **envp)
{
	char	*command;
	char *pc;

	command = ft_strdup("'m   '");
	pc = command;
struct 
{
	char	split[2];
	size_t	commandsz;
	int		expandsegment;
	int		firstnonblank;
} t_sanitizer, tszr;
	ft_bzero(tszr.split, 2);
	tszr.commandsz = ft_strlen(command);
	tszr.firstnonblank = 0;
	tszr.expandsegment = command[0] == '\'';
	if (tszr.expandsegment == 0)
		while (*pc && ft_isblank(*(pc++)))
			tszr.firstnonblank++;
	pc = command;
	ft_striteri(command, single_quotetozero);
	char **splitcmd = ft_split_l(command, tszr.split, tszr.commandsz);
	char **psegment;
	psegment = splitcmd;
	//while (splitcmd &&(tszr.split[1]-- > 0) && psegment++)
	while (psegment++)
	{
		//if (tszr.expandsegment && ft_strlen(*(psegment - 1)))
		ft_putstr_fd(*(psegment - 1), 1);
		if (tszr.expandsegment)
		{
			ft_putendl_fd("Expand", 1);
			ft_bzero(t_sanitizer.split, 2);
			ft_striteri(*(psegment - 1), double_quotetozero);
			ft_split_l(*(psegment - 1), t_sanitizer.split, ft_strlen(*(psegment - 1)));
		}
		else
			ft_putendl_fd("NO Expand", 1);
		tszr.expandsegment = !tszr.expandsegment;
	}
	if(!splitcmd)
		return (1);
	//else
	//ft_free
	
	
	
	/*
	command = ft_strdup("'");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	command = ft_strdup("''");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	command = ft_strdup("h'o'la");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	command = ft_strdup("echo'' hola");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	*/
	size_t	commandsz;
	command = ft_strdup("echo\\'\\\' hola");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	command = ft_strdup("echo'\\'\\\'' hola, es ok aunque no lo parezca");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);
	/*while (commandsz-- > 0)
		if ((*pc++) != '\\')
			ft_putchar(*(pc-1));
		else if ((*(pc - 1) == '\\') && (*(pc - 1)) == *pc)
		{
			ft_putchar(*(pc - 1));
			commandsz--;
		}
		*/
	command = ft_strdup("echo\'\"\"\' hola");
	pc = command;
	commandsz = ft_strlen(command);
	ft_striteri(command, single_quotetozero);
	while (commandsz-- > 0)
		ft_putchar(*pc++);
	ft_putendl_fd("", 1);	
	return (0);
}

char zzz(unsigned int pos, char ps)
{
	return (ps);
}
int main_adios(int argc, char **argv, char **envp)
{
	/*t_Tokenizer	*ptk;
	t_tokenizerImpl **p;
	
	ptk = getTokenizer(toknzrFactory());
	ptk->execute = exec_void;
	ptk->execute(p, (void*)0);
	ptk->execute = exec_valid;
	ptk->execute(p, (void*)0);
	*/
	char *command;
	char *pc;
	char quoted_command;
	char *command2;
	size_t commandlen;
	command = ft_strdup("echo \"marc\" \"serg\"");
	commandlen = ft_strlen(command);
	command2 = ft_strmapi(command, zzz);
	ft_putendl_fd(command2, 1);
	if (ft_strlen(command2) == commandlen);
	
	command = ft_strdup("echo '\"marc\"' \"serg\"");
	commandlen = ft_strlen(command);
	pc = command;
	command2 = ft_strmapi(command, zzz);
	ft_putendl_fd(command2, 1);
	if (ft_strlen(command2) == commandlen);
	
	
	///----------------------
	command = ft_strdup("   'hola'que'tal?'serg'");
	pc = command;
	while (*pc++ && ft_isblank(*(pc - 1)))
		if ((*(pc - 1) == '\'') || (*(pc - 1) == '\"'))
			break;
	quoted_command = *(pc - 1);
	sanitizes(&command, "\'\"");
	ft_putendl_fd(command, 1);
	command = ft_strdup("   '\"hola\"'\"que\"'tal?'serg'");
	pc = command;
	while (*pc++ && ft_isblank(*(pc - 1)))
		if ((*(pc - 1) == '\'') || (*(pc - 1) == '\"'))
			break;
	quoted_command = *(pc - 1);
	sanitizes(&command, "\'\"");
	ft_putendl_fd(command, 1);
	return (0);
	
	/*pc = command;
	char **quoted = ft_split(command, '\''), **pquoted;
	char *result = NULL, *newresult=NULL;
	pquoted = quoted;
	while (*pquoted++)
	{
		newresult = ft_strjoin(result, *(pquoted - 1));
		if (!newresult)
			 break;
		if (result)
			free(result);
		result = newresult;
	}
	if (!result)//if (errno || !result)
		ft_putendl_fd(command, 2);
	*/
	
	
	/*command = (void*) 0;
	pc = command;
	while(*ft_token(&pc))
		;
	pc = command;
	command = "";
	while(*ft_token(&pc))
		;
	command = ft_strdup("#");
	pc = command;
	while(*ft_token(&pc))
		;
	command = ft_strdup("#asdasdasdasdasdasdsadasd");
	pc = command;
	while(*ft_token(&pc))
		;
		**/
	command = ft_strdup("'hola''que''tal?'serg'");
	pc = command;
	while(*ft_token(&pc))		
	command = ft_strdup("'hola'que'tal?'serg'");
	pc = command;
	while(*ft_token(&pc))
	command = ft_strdup("'''hola!!");
	pc = command;
	while(*ft_token(&pc))
	;					
	command = ft_strdup("'");
	pc = command;
	while(*ft_token(&pc))
	;
	command = ft_strdup("''");
	pc = command;
	while(*ft_token(&pc))
	;	
	command = ft_strdup("'''");
	pc = command;
	while(*ft_token(&pc))
	;		
	command = ft_strdup("'''hola!!");
	pc = command;
	while(*ft_token(&pc))
	;			
	//-----------------
	command = ft_strdup("#");
	pc = command;
	while(*ft_token(&pc))
	;	
	//ft_token(&"#");
	//ft_token(&"#\\");
	//ft_token(&"#\n");
	//ft_token(&"#\\\n");
		

	return (0);
}

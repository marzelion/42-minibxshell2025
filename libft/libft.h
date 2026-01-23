/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:09:00 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/16 13:47:47 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
/*
typedef unsigned long	t_size_t;
*/
typedef size_t				t_size_t;
typedef unsigned long long	t_ulonglong;
typedef void				**t_vpp;
/*
 * # ifdef _FTBONUS
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/*
# endif
*/
void		*ft_free(void *p, t_vpp pp);
int			ft_perror(int retval, const char *s, int ignore, int succ);
char		*newstr(char **buffer, size_t bufsize);
# define FT_NEWSTR newstr

int			ft_isalpha(int c);
int			ft_isblank(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspacbk(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi_val(const char *nptr, int *result);
int			ft_atoi_deprec(const char *nptr);
void		*ft_calloc(t_size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

/*
Description
ft_substr
-
s: The original string from which to create the
substring.
start: The starting index of the substring within
’s’.
len: The maximum length of the substring.
The substring.
NULL if the allocation fails.
malloc
 * */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*
 *ft_strjoin
-
s1: The prefix string.
s2: The suffix string.
The new string.
NULL if the allocation fails.
malloc
Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2w
 * */
char		*ft_strjoin(char const *s1, char const *s2);

# define FT_JOIN ft_strjoin

/*
s1: The string to be trimmed.
set: The string containing the set of characters
to be removed.
The trimmed string.
NULL if the allocation fails.
 * */
char		*ft_strtrim(char const *s1, char const *s2);
/*s: The string to be split.
c: The delimiter character.
The array of new strings resulting from the split.
NULL if the allocation fails.
malloc, free
 */
size_t		ft_strsplit_size(char **arridx);
int			ft_countfilledsubstr(const char *s, char c);

# define FT_SPLTCNT ft_countfilledsubstr

char		**ft_strsplit_release(char ***arr);

char		**ft_split(char const *start, char c);

char		*ft_itoa(int n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putchar(char c);
size_t		ft_putstr_fd(char *s, int fd);
size_t		ft_putstr(char *s);
size_t		ft_putendl_fd(char *s, int fd);
size_t		ft_putnbr_fd(int nb, int fd);
size_t		ft_putnbr(int nb);
size_t		ft_puthex(t_ulonglong n, unsigned int base, const char *digits);
/*# ifdef _FTBONUS
*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*# endif
 * */
int			ft_check_repeated(int val, int **assign, size_t numlen);
size_t		ft_parsetoints(size_t argc, char **argv, int **assign);
/**/
int			ft_debug_printf(int retcode, const char *fmt, ...);

/* norminette valid in the cluster !!! */
# define FT_DBGPRINT ft_debug_printf
#endif

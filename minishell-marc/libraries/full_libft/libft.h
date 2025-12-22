/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:26:47 by marcfer3          #+#    #+#             */
/*   Updated: 2025/11/19 18:05:43 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_isalpha(int c);
int		ft_atoi(char const *str);
void	ft_bzero(void *ptr, size_t num);
int		ft_isascii(int c);
int		ft_isdigit(char c);
int		ft_isprint(int c);
void	*ft_memchr(const void *ptr, int value, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(char const *str, int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, char const *src, size_t dest_size);
size_t	ft_strlcpy(char *dest, char const *src, size_t len_dest_buffer);
size_t	ft_strlen(char const *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(char const *stack, char const *aguja, size_t n);
char	*ft_strrchr(char const *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t nblocks, size_t element_size);
char	*ft_strdup(char const *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_isalnum(int c);
int		ft_custom_atoi(const char *str);

#endif

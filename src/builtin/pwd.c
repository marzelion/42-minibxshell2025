/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:18:51 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/12 17:18:51 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
//#include "../../minishell.h"
#include "minishellx.h"

#include "libft.h"
#include <stddef.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>

struct stat	*ft_stat(const char *path, struct stat *st)
{
	if (!st)
		return (st);
	if (lstat(path, st) != 0)
	{
		perror("stat:");
		return (NULL);
	}
	return (st);
}

struct dirent	*ft_readdir(DIR *dp, struct dirent **e)
{
	if (!dp || !e)
		return (NULL);
	*e = readdir(dp);
	return (*e);
}

int	put_getcwd_s(int fd)
{
	char	*buf;
	char	ret;

	ret = 0;
	buf = NULL;
	buf = getcwd(NULL, 0);
	if (!buf)
	{
		perror("get cwd memory:");
		return (ret);
	}
	if (errno)
	{
		perror("get cwd:");
		if (buf == NULL)
			return (ret);
	}
	if (ft_strlen(buf) > 1)
		ret = ft_putstr_fd(buf, fd);
	free (buf);
	return (ret);
}

/* 
 * need to deep 
 * if (((c->st_ino == p->st_ino) && (c->st_dev != p->st_dev)) 
 * ...|| (c->st_ino < 12))
 * 	if (!dp)
		return (-1);
 */
int	_cwd(int fd, struct stat *c, struct stat *p, int _cd)
{
	DIR				*dp;
	struct dirent	*entry;
	int				r;

	if (!c || !p || (_cd == -1))
		return (-1);
	r = c->st_ino < 12;
	if (((c->st_ino == p->st_ino) && (c->st_dev != p->st_dev)) || r)
		return (put_getcwd_s(fd) + ft_putstr_fd("/", fd));
	else if ((c->st_ino == p->st_ino) && (c->st_dev == p->st_dev))
		return (ft_putstr_fd("/", fd));
	dp = opendir("..");
	while (ft_readdir(dp, &entry) != NULL)
	{
		if (entry->d_ino == c->st_ino)
		{
			r = _cwd(fd, ft_stat(".", c), ft_stat("..", p), chdir(".."));
			if (entry->d_ino != 2)
				r += ft_putstr_fd(entry->d_name, fd) + ft_putstr_fd("/", fd);
			break ;
		}
	}
	if (dp)
		closedir(dp);
	return (r);
}

/*
typedef struct s_mx_pwd
{
	int			pipeok;
	int			pd[2];
	char		*buf;
	struct stat	s0;
	struct stat	s1;
} t_mx_pwd;

int main(int argc, char **argv, char **envp, t_msh x)
*/
int	ft_pwd(int c, char **v, char **e, t_msh x)
{
	int		t;
	char	*tm;

	tm = NULL;
	if (chdir(".") < 0 || c || (v && !XCTOR(&x, e, FTPIPE(x.evm.pd, 1, 0))))
		return (t_mini_dtor(&x));
	t = _cwd(x.wdm.pd[1], ft_stat(".", &x.wdm.s0), ft_stat("..", &x.wdm.s1), 0);
	if (!errno && (t > 0))
	{
		if (!x.wdm.buf || (x.wdm.buf && ft_free(x.wdm.buf, (t_vpp)&x.wdm.buf)))
			x.wdm.buf = malloc((t + 1) * sizeof(char));
		if (x.wdm.buf && (read(x.wdm.pd[0], x.wdm.buf, t) > 0))
		{
			if (t > 1)
				x.wdm.buf[t - 1] = 0;
			x.wdm.buf[t] = 0;
			if (x.batchmode < 2)
				ft_putendl_fd(x.wdm.buf, 1);
		}
	}
	if (!errno && (t > 1) && (x.wdm.buf && (chdir(x.wdm.buf) > -1) && !errno))
		tm = FT_JOIN("OLDPWD=", x.evm.v(&x.evm, "PWD"));
	if (tm && (x.evm.create(&x.evm, tm) || (ft_free(tm, (t_vpp)&tm))) && !errno)
		tm = FT_JOIN("PWD=", x.wdm.buf);
	t = tm && (x.evm.create(&x.evm, tm) || (ft_free(tm, (void **)&tm)));
	return ((t < 0) || t_mini_dtor(&x));
}
/*if (errno  || (t == -1) || (x.wdm.buf && (chdir(x.wdm.buf) != -1) || errno)
	perror("pwd:");
if (x.evm.create(&x.evm, FT_JOIN("OLDPWD=", x.evm.v(&x.evm, "PWD"))))
	if (errno || !x.evm.create(&x.evm, ft_strjoin("PWD=", x.wdm.buf)))
		perror("setenv_pwd:");
* */

/*
 * 	//if (close(x.wdm.pd[0]) + close(x.wdm.pd[1]) || ft_memset(x.wdm.pd, 0, 2))
	//	perror("post_pwd");ft_pipeclose(x.wdm.pd);
 * ERANGE The size argument is less than the length of the absolute  path‐
name  of  the  working directory, including the terminating null
byte.  You need to allocate a bigger array and try again.
 * */
/*
int	ft_pwd(int argc, char *argv[], char *envp[])
{
	char	*current_path;

	current_path = ft_calloc(PATH_MAX, sizeof(char));
	if (current_path != NULL)
	{
		perror("No hay menoria para cwd!!");
		return(ENOMEM);
	}		
	if (getcwd(current_path, PATH_MAX) == NULL)
	{
		perror("getcwd");
		return(ENOMEM);
	}	
	if (current_path && (errno == 0))
	{
		ft_printf("%s", current_path);
		free(current_path);
	}
	return (0);
}
*/

/*void update_environment(const char *path) {
	if (setenv("PWD", path, 1) == -1) {
		perror("No se pudo actualizar la variable de entorno PWD");
	}
}
*/
/*
void execute_pwd() {
	char cwd[PATH_MAX] = "/";
	char temp[PATH_MAX];
	int length = 1;  // Contador para manejar la longitud del path

	// Cambiar al directorio actual
	if (chdir(".") != 0) {
		perror("Error al cambiar de directorio");
		return;
	}
	// Abrir el directorio raíz
	DIR *dir = opendir("/");
	if (dir == NULL) {
		perror("Error al abrir el directorio raíz");
		return;
	}

	// Leer los directorios hasta llegar a la raíz
	while (getcwd(temp, sizeof(temp)) != NULL) {
		struct dirent *entry;
		char *lastSlash = strrchr(temp, '/');

		// Construir el path desde la raíz
		while ((entry = readdir(dir)) != NULL) {
			if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") 
			* ......!= 0) {
				if (strcmp(lastSlash + 1, entry->d_name) == 0) {
					if (length + strlen(entry->d_name) + 1 < sizeof(cwd)) {
						strcat(cwd, entry->d_name);
						strcat(cwd, "/");
						length += strlen(entry->d_name) + 1;
					}
					break;
				}
			}
		}

		// Si hemos llegado a la raíz, salir del bucle
		if (lastSlash == temp) {
			break;
		}
		// Moverse al directorio padre
		chdir("..");
	}

	// Imprimir el directorio y actualizar la variable de entorno
	printf("%s\n", cwd);
  //  update_environment(cwd);

	// Cerrar el directorio raíz
	closedir(dir);
}
*/
/*
void get_canonical_path(char *buffer, size_t size) {
    
    char current_path[1024];
    char *ptr = getcwd(current_path, sizeof(current_path));
    
    if (ptr == NULL) {
        perror("Error al obtener el directorio de trabajo");
        exit(EXIT_FAILURE);
    }
    strcpy(buffer, current_path); // Copia el directorio actual al buffer
    char *token = strtok(buffer, "/");
    char resolved_path[1024] = "";    
    while (token != NULL) {
        if (strcmp(token, "") != 0) {
            strcat(resolved_path, "/");
            strcat(resolved_path, token);
            struct stat path_stat;
            if (stat(resolved_path, &path_stat) != 0) {
                perror("Error al obtener información del directorio");
                exit(EXIT_FAILURE);
            }

            // Verifica si es un directorio
            if (!S_ISDIR(path_stat.st_mode)) {
                fprintf(stderr, "%s no es un directorio\n", resolved_path);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, "/");
    }

    // Copia la ruta canónica final al buffer
    strcpy(buffer, resolved_path);
}
* */
/*int main() {
	char cwd[1024];
	execute_pwd();
    //get_canonical_path(cwd, sizeof(cwd));
    printf("%s\n", cwd);
	return 0;
}
*/
/*int main(int argc, char **argv)
{
	struct dirent *pdir;
	DIR *dir;
	
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("Error al abrir el directorio actual");
		return (errno);
	}
	if (chdir(".") != 0)
		perror("Error al cambiar el directorio actual");
	
	while( (pdir = readdir(dir)) != NULL)
	{
	//	ft_putendl_fd(dir->d_name);
		printf("%s\n", pdir->d_name);
	}
	closedir(dir);
}
*/

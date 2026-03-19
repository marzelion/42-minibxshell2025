/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:46 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/09 11:02:48 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

/*
 * 
 * */ 
t_pipex	*ft_pipex_split(t_mini *x, char **line, t_pipex *p);

int		ft_pipex(t_mini *x, char **lne, int pipexsz);

#endif

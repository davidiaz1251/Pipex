/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:56 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/21 18:46:25 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include "Libft/libft.h"
# include <fcntl.h>

typedef struct s_pipex
{
	int		fd[2];
	int		pid[2];
	char	**path;
	char	**comman;
	char	*route;
}	t_pipex;

char	**find_path(char **env);
void	ft_error(char *err);
char	*check_path(char **path, char *comman);
void	free_matrix(char **array);

#endif
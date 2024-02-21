/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:59:08 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/21 15:47:20 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(char *path, char *comman)
{
	char *comman_;
	char *new_path;

	comman_ = ft_strjoin("/", comman);
	new_path = ft_strjoin(path, comman_);
	free(comman_);
	return (new_path);
}


char	*check_path(char **path, char *comman)
{
	char	*path_all;
	int		i;

	i = 0;
	while (path[i])
	{
		path_all = join_path(path[i], comman);
		if (!access(comman, R_OK))
			return (comman);
		else if (!access(path_all, R_OK))
			return (path_all);
		free(path_all);
		i++;
	}
	return (NULL);
}
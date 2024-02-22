/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:59:08 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/22 18:44:09 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*join_path(char *path, char *command)
{
	char *command_;
	char *new_path;

	command_ = ft_strjoin("/", command);
	new_path = ft_strjoin(path, command_);
	free(command_);
	return (new_path);
}


char	*check_path(char **path, char *command)
{
	char	*path_all;
	int		i;

	i = 0;
	if (ft_strrchr(command, '/') && !access(command, X_OK))
		return (command);
	else if (ft_strrchr(command, '/') && access(command, X_OK))
		return (NULL);
	while (path[i])
	{
		path_all = join_path(path[i], command);
		if (!access(path_all, X_OK))
			return (path_all);
		free(path_all);
		i++;
	}
	return (NULL);
}

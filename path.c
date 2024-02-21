/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:08:32 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/21 12:13:45 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **find_path(char **env)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			return (ft_split(env[i] + 5, ':'));	
	}
	return (NULL);
}

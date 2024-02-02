/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:51 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/02 11:27:47 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *str)
{
	int	fd;

	fd = open()
}
void	process_one(char **argv, char **env)
{
	int infile;

	infile = open_file(argv[1]);
}
int	main(int argc, char **argv, char **env)
{
	int fd[2];
	int pid[2];
	
	if(argc == 5)
	{
		pipe(fd);
		pid[0] = fork();
		if (!pid[0])
			process_one(argv, env);
		else
		{
			close(fd[0]);
		}
		//printf("%s\n",ft_strnstr(env[i], "PATH", ft_strlen(env[i])));
	}
	return (0);
}
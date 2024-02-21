/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:51 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/02/21 18:46:41 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY );
	if(fd == -1)
		ft_error("Error");
	return (fd);
}

void	process_one(char **argv, char **env, t_pipex *pipex)
{
	int		infile;
	
	close(pipex->fd[0]);
	infile = open_file(argv[1]);
	pipex->comman = ft_split(argv[2], ' ');
	if (!pipex->comman)
		ft_error("Error Split Comman");
	pipex->route = check_path(pipex->path, pipex->comman[0]);
	if(!pipex->route)
		ft_error("Error");
	dup2(infile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	execve(pipex->route, pipex->comman, env);
}
void	process_two(char **argv, char **env, t_pipex *pipex)
{
	int	output;
	
	close(pipex->fd[1]);
	output = open(argv[4], O_RDWR | O_CLOEXEC | O_TRUNC | O_CREAT, 0644);
	if (output == -1)
		ft_error("Error");
	pipex->comman = ft_split(argv[3], ' ');
	if (!pipex->comman)
		ft_error("Error Split Comman");
	pipex->route = check_path(pipex->path, pipex->comman[0]);
	if(!pipex->route)
		ft_error("Error");
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	execve(pipex->route, pipex->comman, env);
}
int	main(int argc, char **argv, char **env)
{
	t_pipex pipex;

	if(argc == 5)
	{
		pipex.path = find_path(env);
		if (!pipex.path)
			ft_error("Error Path");
		if (pipe(pipex.fd) == -1)
			ft_error("Error");
		pipex.pid[0] = fork();
		if (!pipex.pid[0])  
			process_one(argv, env, &pipex);
		pipex.pid[1] = fork();
		if (!pipex.pid[1])
			process_two(argv, env, &pipex);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		free_matrix(pipex.path);
		waitpid(pipex.pid[0], NULL, 0);
		waitpid(pipex.pid[1], NULL, 0);		
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:51 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:32 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	int fd[2];
	int pid;
	int status;

	pipe(fd);
	pid = fork();

	if (!pid)
	{
		close(fd[0]);
	}
	else
	{
		
	}
	return (0);
}
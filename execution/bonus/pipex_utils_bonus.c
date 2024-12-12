/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:54:56 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/13 01:44:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

void	pipe_generating(int	*use_pipe)
{
	if (pipe(use_pipe) == -1)
	{
		perror("pipex: pipe failed: \n");
		exit(1);
	}
}

void	redirect(int in, int stdin, int out, int stdout)
{
	if (dup2(in, stdin) < 0)
	{
		perror("pipex: Redirecting Input Error \n");
		exit(1);
	}
	if (dup2(out, stdout) < 0)
	{
		perror("pipex: Redirecting Output Error \n");
		exit(1);
	}
	close(in);
	close(out);
}

void	pipex_fork(t_pipex *pipex, int *pipe)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("pipex: fork failed: \n");
		close(pipe[0]);
		close(pipe[1]);
		exit(1);
	}
}

void	last_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->ac)
	{
		if (pipex->track[i] == 1)
		{
			free(pipex->av[i]);
			pipex->av[i] = NULL;
		}
		i++;
	}
	if (pipex->track)
		free(pipex->track);
	pipex->track = NULL;
}

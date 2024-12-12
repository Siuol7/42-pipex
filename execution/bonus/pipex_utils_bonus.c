/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:54:56 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 23:17:41 by caonguye         ###   ########.fr       */
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

void	pipex_fork(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("pipex: fork failed: \n");
		exit(1);
	}
}

void	last_free(t_pipex *pipex, int *track)
{
	int	i;

	i = 0;
	while (i < pipex->ac)
	{
		if (track[i] == 1)
		{
			free(pipex->av[i]);
			pipex->av[i] = NULL;
		}
		i++;
	}
	free(track);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:54:56 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	redirect(int in, int stdin, int out, int stdout)
{
	if (dup2(in, stdin) < 0)
	{
		perror("pipex: Redirecting Input Error\n");
		exit(1);
	}
	if (dup2(out, stdout) < 0)
	{
		perror("pipex: Redirecting Output Error\n");
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
		while (pipex->fork_times--)
			waitpid(0, &pipex->wait_status, 0);
		perror("pipex: fork failed: \n");
		close(pipe[0]);
		close(pipe[1]);
		exit(1);
	}
}

void	pipex_wait(t_pipex *pipex)
{
	while (pipex->fork_times--)
	{
		if (waitpid(0, &pipex->wait_status, 0) == pipex->pid)
		{
			if (WIFEXITED(pipex->wait_status))
				pipex->exit_status = WEXITSTATUS(pipex->wait_status);
			else if (WIFSIGNALED(pipex->wait_status))
				pipex->exit_status = 128 + WTERMSIG(pipex->wait_status);
		}
	}
}

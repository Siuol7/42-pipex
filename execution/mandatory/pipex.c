/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	first_cmd(t_pipex *pipex)
{
	pipex_fork(pipex, pipex->pipe);
	if (pipex->pid == 0)
	{
		close(pipex->pipe[0]);
		pipex->fd[0] = open(pipex->av[1], O_RDONLY);
		if (pipex->fd[0] < 0)
		{
			ft_printf_fd(2, "pipex: %s: %s\n",
				pipex->av[1], strerror(errno));
			close(pipex->pipe[1]);
			exit(1);
		}
		redirect(pipex->fd[0], STDIN_FILENO, pipex->pipe[1], STDOUT_FILENO);
		cmd_exec(pipex->av[2], pipex);
	}
	pipex->fork_times++;
	close(pipex->pipe[1]);
}

static void	next_cmd(t_pipex *pipex)
{
	pipex_fork(pipex, pipex->pipe);
	if (pipex->pid == 0)
	{
		close(pipex->pipe[1]);
		pipex->fd[1] = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex->fd[1] < 0)
		{
			ft_printf_fd(2, "pipex: %s: %s\n",
				pipex->av[pipex->ac - 1], strerror(errno));
			close(pipex->pipe[0]);
			exit(1);
		}
		redirect(pipex->pipe[0], STDIN_FILENO, pipex->fd[1], STDOUT_FILENO);
		cmd_exec(pipex->av[pipex->ac - 2], pipex);
	}
	pipex->fork_times++;
	close(pipex->pipe[0]);
}

void	pipexshell(t_pipex *pipex)
{
	if (pipe(pipex->pipe) == -1)
	{
		perror("pipex: pipe failed: \n");
		exit(1);
	}
	first_cmd(pipex);
	next_cmd(pipex);
	pipex_wait(pipex);
}

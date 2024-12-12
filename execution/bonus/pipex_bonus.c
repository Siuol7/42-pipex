/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 23:26:56 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

static void	heredoc_cmd(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("pipex: fork failed: \n");
		exit(1);
	}
	else if (pipex->pid == 0)
	{
		pipe_generating(pipex->heredoc);
		read_heredoc(pipex);
		close(pipex->heredoc[1]);
		close(pipex->main_pipe[0]);
		redirect(pipex->heredoc[0],
			STDIN_FILENO, pipex->main_pipe[1], STDOUT_FILENO);
		cmd_exec(pipex->av[3], pipex->envp);
	}
	pipex->fork_times++;
}

static void	first_cmd(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("pipex: fork failed: \n");
		exit(1);
	}
	else if (pipex->pid == 0)
	{
		close(pipex->main_pipe[0]);
		pipex->fd[0] = open(pipex->av[1], O_RDONLY);
		if (pipex->fd[0] < 0)
		{
			ft_printf_fd(2, "pipex: line 47: %s: %s\n",
				pipex->av[1], strerror(errno));
			close(pipex->main_pipe[1]);
			exit(1);
		}
		redirect(pipex->fd[0],
			STDIN_FILENO, pipex->main_pipe[1], STDOUT_FILENO);
		cmd_exec(pipex->av[2], pipex->envp);
	}
	pipex->fork_times++;
}

static void	next_cmd(t_pipex *pipex, int i)
{
	close(pipex->main_pipe[1]);
	pipe_generating(pipex->sub_pipe);
	pipex_fork(pipex);
	pipex->fork_times++;
	if (pipex->pid < 0)
	{
		perror("pipex: fork failed: \n");
		exit(1);
	}
	else if (pipex->pid == 0)
	{
		close(pipex->sub_pipe[0]);
		redirect(pipex->main_pipe[0],
			STDIN_FILENO, pipex->sub_pipe[1], STDOUT_FILENO);
		cmd_exec(pipex->av[i], pipex->envp);
	}
	redirect(pipex->sub_pipe[0],
		pipex->main_pipe[0], pipex->sub_pipe[1], pipex->main_pipe[1]);
}

static void	last_cmd(t_pipex *pipex)
{
	close(pipex->main_pipe[1]);
	pipex_fork(pipex);
	pipex->fork_times++;
	if (pipex->pid == 0 && pipex->heredoc_sign == 1)
	{
		close(pipex->main_pipe[1]);
		pipex->fd[1] = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		if (pipex->fd[1] < 0)
			error_open(pipex, 93);
		redirect(pipex->main_pipe[0], 0, pipex->fd[1], 1);
		cmd_exec(pipex->av[pipex->ac - 2], pipex->envp);
	}
	else if (pipex->pid == 0 && pipex->heredoc_sign != 1)
	{
		close(pipex->main_pipe[1]);
		pipex->fd[1] = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex->fd[1] < 0)
			error_open(pipex, 103);
		redirect(pipex->main_pipe[0], 0, pipex->fd[1], 1);
		cmd_exec(pipex->av[pipex->ac - 2], pipex->envp);
	}
	close(pipex->main_pipe[0]);
}

void	pipexshell(t_pipex *pipex)
{
	int	i;

	i = 3;
	pipe_generating(pipex->main_pipe);
	if (pipex->heredoc_sign == 1)
	{
		heredoc_cmd(pipex);
		i = 4;
	}
	else
		first_cmd(pipex);
	while (i < pipex->ac - 2)
		next_cmd(pipex, i++);
	last_cmd(pipex);
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

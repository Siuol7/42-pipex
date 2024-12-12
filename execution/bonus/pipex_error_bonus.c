/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 03:28:46 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 03:24:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

void	error_read(char *text, t_pipex *pipex)
{
	free(text);
	close (pipex->heredoc[0]);
	close (pipex->heredoc[1]);
	perror ("pipex: reading stdin failed: \n");
	exit(1);
}

void	error_envp(char **cmd)
{
	ft_printf_fd(2, "pipex: line 82: %s: %s\n", *cmd, strerror(ENOENT));
	ft_free_2d((void **)cmd);
	exit(127);
}

void	error_open(t_pipex *pipex, int line)
{
	ft_printf_fd(2, "pipex: line %d: %s: %s\n",
		line, pipex->av[pipex->ac - 1], strerror(errno));
	close(pipex->main_pipe[0]);
	exit(1);
}

void	error_read_quote_dquote(char *text)
{
	free(text);
	perror ("pipex: reading stdin failed: \n");
	exit(1);
}

void	error_isdir(char **cmd)
{
	ft_printf_fd(2, "pipex: line 77: %s: Is a directory\n", *cmd);
	ft_free_2d((void **)cmd);
	exit(126);
}


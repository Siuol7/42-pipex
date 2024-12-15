/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:54:56 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/15 06:50:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

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

void	last_free(t_pipex *pipex)
{
	int	i;

	i = 2;
	while (i < pipex->ac -1)
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

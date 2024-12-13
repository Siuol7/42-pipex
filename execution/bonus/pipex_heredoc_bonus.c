/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:41:52 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/08 09:11:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

void	read_heredoc(t_pipex *pipex)
{
	char	buffer[1024];
	size_t	bytesread;

	while (1)
	{
		bytesread = read(STDIN_FILENO, buffer, 1023);
		if (bytesread < 0)
			error_read(buffer, pipex);
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		if ((bytesread - 1) == ft_strlen(pipex->av[2]))
		{
			if (ft_strncmp(buffer, pipex->av[2], ft_strlen(pipex->av[2])) == 0)
				break ;
			write(pipex->heredoc[1], buffer, bytesread);
		}
	}
}

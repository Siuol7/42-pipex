/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:41:52 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:37:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

static char	*expand(char *text, int current_size)
{
	char	*newtext;

	newtext = ft_calloc(current_size + BUFFER_SIZE, 1);
	if (!newtext)
	{
		free(text);
		exit(1);
	}
	ft_memcpy(newtext, text, current_size);
	free (text);
	return (newtext);
}

static char	*gnl_heredoc(t_pipex *pipex, int i)
{
	char	word;
	char	*text;
	int		readbytes;

	text = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!text)
		exit(1);
	while (1)
	{
		readbytes = read(0, &word, 1);
		if (readbytes == -1)
			error_read(text, pipex);
		if (readbytes == 0 && i == 0)
			return (NULL);
		if (word == '\n')
			break ;
		text[i++] = word;
		if (i >= BUFFER_SIZE)
			text = expand(text, i);
	}
	text[i] = '\0';
	return (text);
}

void	read_heredoc(t_pipex *pipex)
{
	char	*text;

	while (1)
	{
		text = gnl_heredoc(pipex, 0);
		if (!text)
			break ;
		if (ft_strcmp(text, pipex->av[2]) == 0)
		{
			free(text);
			break ;
		}
		ft_printf_fd(pipex->heredoc[1], "%s\n", text);
		free(text);
	}
}

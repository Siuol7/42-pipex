/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_quote_dquote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:25 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 12:31:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

static	int	ft_quote_dquote_check(char *cmd, int i, char sign)
{
	while (cmd[i])
	{
		if (cmd[i] == sign)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_quote_dquote_len(char *string, char sign)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == sign)
			break ;
		i++;
	}
	return (i);
}

char	*ft_quote_dquote(char *cmd, int index, t_pipex *pipex)
{
	int		i;
	int		opened;
	char	*res;
	char	*final;

	i = -1;
	opened = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			opened = ft_quote_dquote_check(cmd, i + 1, cmd[i]);
			if (opened == -1)
			{
				pipex->track[index] += 1;
				res = read_quote_dquote(cmd[i]);
				final = ((ft_strjoin(cmd, res)));
				free(res);
				return (final);
			}
			else
				i = opened;
		}
	}
	return (cmd);
}

void	fill_quote_dquote(t_pipex *pipex)
{
	int		i;

	i = 2;
	while (i < (pipex->ac - 1))
	{
		pipex->av[i] = ft_quote_dquote(pipex->av[i], i, pipex);
		i++;
	}
}

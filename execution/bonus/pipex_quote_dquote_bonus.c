/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_quote_dquote_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:25 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 23:15:05 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

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

char	*ft_quote_dquote(char *cmd, int *track, int index)
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
				track[index]++;
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

void	fill_quote_dquote(t_pipex *pipex, int *track)
{
	int		i;

	if (pipex->heredoc_sign == 1)
		i = 3;
	else
		i = 2;
	while (i < (pipex->ac - 1))
	{
		pipex->av[i] = ft_quote_dquote(pipex->av[i], track, i);
		i++;
	}
}

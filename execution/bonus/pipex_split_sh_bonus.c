/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_sh_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:45:47 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex_bonus.h"

static int	ft_wordcount(char *s, char c, int cnt, int i)
{
	int		flag;

	flag = 1;
	while (s[i])
	{
		if (s[i + 1] && (s[i] == '\'' || s[i] == '\"'))
		{
			cnt++;
			i += ft_quote_dquote_len(&s[i + 1], s[i]);
			flag = 1;
		}
		else if (flag == 1 && s[i] != c)
		{
			cnt++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (cnt);
}

int	ft_wordlength(char *start, char c)
{
	int	wlen;
	int	i;

	wlen = 0;
	i = 0;
	while (start[i] && start[i] != c
		&& start[i] != '\'' && start[i] != '\"')
	{
		wlen++;
		i++;
	}
	return (wlen);
}

int	ft_quotelength(char *start, char c)
{
	int	wlen;
	int	i;

	wlen = 0;
	i = 0;
	while (start[i] && start[i] != c)
	{
		wlen++;
		i++;
	}
	return (wlen);
}

char	**ft_split_sh(char *s, char c)
{
	char	**final;
	int		totlen;

	if (!s)
		return (NULL);
	totlen = ft_wordcount(s, c, 0, 0);
	final = (char **)malloc((totlen + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	return (ft_splitting(final, s, c));
}

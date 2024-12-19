/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:45:47 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:48:44 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_wordcount(char const *s, char c)
{
	int		flag;
	size_t	i;
	int		cnt;

	flag = 1;
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (flag == 1 && s[i] != c)
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

static	size_t	ft_wordlength(char const *start, char c)
{
	size_t	wlen;
	size_t	i;

	wlen = 0;
	i = 0;
	while (start[i] && start[i++] != c)
		wlen++;
	return (wlen);
}

static void	ft_free(char **final, size_t cur)
{
	while (cur-- > 0)
	{
		free(final[cur]);
		final[cur] = NULL;
	}
	free(final);
	final = NULL;
}

static char	**ft_splitting(char **final, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	wlen;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			wlen = ft_wordlength(&s[j], c);
			final[i] = ft_substr(s, j, wlen);
			if (!final[i])
			{
				ft_free(final, i);
				return (NULL);
			}
			i++;
			j += wlen;
		}
	}
	final[i] = NULL;
	return (final);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	totlen;

	if (!s)
		return (NULL);
	totlen = ft_wordcount(s, c);
	final = (char **)malloc((totlen + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	return (ft_splitting(final, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_splitting_sh.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:10:39 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 23:10:22 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

static	void	ft_isword(char **final, char *s, int *wlen, int j)
{
	*wlen = ft_wordlength(&s[j], ' ');
	*final = ft_substr(s, j, *wlen);
}

static	void	ft_isquote_dquote(char **final, char *s, int *wlen, int j)
{
	*wlen = ft_quotelength(&s[j + 1], s[j]);
	*final = ft_substr(s, j + 1, *wlen);
	*wlen += 2;
}

char	**ft_splitting(char **final, char *s, char c)
{
	int	wlen;
	int	i;
	int	j;

	i = 0;
	j = 0;
	wlen = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			if (s[j] && (s[j] == '\'' || s[j] == '\"'))
				ft_isquote_dquote(&final[i], s, &wlen, j);
			else
				ft_isword(&final[i], s, &wlen, j);
			if (ft_free_process_2d(final, i) == 0)
				return (NULL);
			i++;
			j += wlen;
		}
	}
	final[i] = NULL;
	return (final);
}

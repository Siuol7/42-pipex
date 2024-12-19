/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_quote_dquote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:25 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:41:30 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

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
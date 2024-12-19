/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_eli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:15:21 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:46 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_eli(char *string, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!string)
		return (NULL);
	while (string[i])
	{
		if (string[i++] != c)
			j++;
	}
	res = malloc(j + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (string[++i])
	{
		if (string[i] != c)
			res[j++] = string[i];
	}
	res[j] = '\0';
	return (res);
}

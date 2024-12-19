/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:09:10 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:52 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_custom_substr(char *s, unsigned int start, size_t len, char *c)
{
	char			*res;
	size_t			i;
	unsigned int	lens;

	i = 0;
	lens = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= lens)
		return (ft_strdup(""));
	if (len > lens - start)
		len = lens - start;
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		if (ft_strichr(c, s[start]) != -1)
			start++;
		else
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

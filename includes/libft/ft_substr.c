/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:03:42 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 00:32:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

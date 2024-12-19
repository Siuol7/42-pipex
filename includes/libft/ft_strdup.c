/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:50:46 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:49:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = -1;
	res = malloc(ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

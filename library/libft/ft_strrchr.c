/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:14:22 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:49:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	val;

	i = ft_strlen(s);
	val = (char)c;
	if (val == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == val)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

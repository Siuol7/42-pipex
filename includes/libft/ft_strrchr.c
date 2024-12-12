/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:14:22 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 00:12:15 by caonguye         ###   ########.fr       */
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

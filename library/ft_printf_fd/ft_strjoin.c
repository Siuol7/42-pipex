/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:20:49 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_printf(char *s1, char *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = malloc(lens1 + lens2 +1);
	if (res == NULL)
		return (NULL);
	ft_memcpy_printf(res, s1, lens1);
	ft_memcpy_printf(res + lens1, s2, lens2);
	res[lens1 + lens2] = '\0';
	return (res);
}

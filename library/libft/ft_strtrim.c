/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:39:08 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:49:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	lens;

	start = 0;
	if (!s1 || !set || !*s1)
		return (ft_strdup(""));
	lens = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (lens > start && ft_strrchr(set, s1[lens]))
		lens--;
	return (ft_substr(s1, start, lens - start + 1));
}

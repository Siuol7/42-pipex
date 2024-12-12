/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:02:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/06 22:20:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	j;

	if ((!dst || !src) && size == 0)
		return (0);
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	j = 0;
	if (lend >= size)
		return (lens + size);
	while (lend + j < size - 1 && src[j])
	{
		dst[lend + j] = src[j];
		j++;
	}
	dst[lend + j] = '\0';
	return (lend + lens);
}

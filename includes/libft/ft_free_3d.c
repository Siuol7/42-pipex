/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:19:34 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 07:16:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_3d(void ***arr)
{
	if (!*arr)
		return ;
	ft_free_2d(*arr);
	*arr = NULL;
}
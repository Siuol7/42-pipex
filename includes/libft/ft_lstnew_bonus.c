/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:29:41 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:48:22 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (void *)content;
	new->next = NULL;
	return (new);
}
// #include <stdio.h>
// int	main()
// {
// 	char	string[5]= "abcd";
// 	int	x = 4;
// 	t_list *test1 = ft_lstnew((void *)string);
// 	t_list *test2 = ft_lstnew((void *)&x);
// 	printf("%s\n", (char *)test1->content);
// 	printf("%d\n", *(int *)test2->content);
// 	return(0);
// }
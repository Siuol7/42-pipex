/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:03:10 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 05:22:50 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include <stdio.h>

// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[8] = "abcde  ";
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head,node2);
// 	ft_lstiter(head, (void *)printf);
// 	return(0);
// }
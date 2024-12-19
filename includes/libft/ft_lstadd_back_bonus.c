/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:03 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:47:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
// #include <stdio.h>

// void	ft_printlst(t_list **head)
// {
// 	t_list	*temp;

// 	temp = *head;
// 	if (!*head)
// 		return ;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }

// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[6] = "abcde";
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head,node2);
// 	ft_printlst(&head);
// 	return(0);
// }
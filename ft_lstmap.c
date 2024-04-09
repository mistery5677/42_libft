/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:06 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:00:07 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_node;

	if (lst == NULL)
		return (0);
	map = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_node);
		lst = lst->next;
	}
	return (map);
}

/*int main()
{
	t_list *head  = malloc(sizeof(t_list));

	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Node 1";
	node2->content = "Node 2";
	node3->content = "Node 3";

	head->next = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("before free: %s\n", (char *)node2->content);
}*/

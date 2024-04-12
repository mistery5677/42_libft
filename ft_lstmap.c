/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:06 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/12 10:28:44 by miafonso         ###   ########.fr       */
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

#include <stdio.h> // For printf

// Function to be applied to each element of the list
void *add_one(void *content)
{
    int *num = (int *)content;
    int *result = malloc(sizeof(int));
    if (result == NULL)
        return NULL;
    *result = *num + 1;
    return result;
}

// Function to delete an integer
void del_int(void *content)
{
    free(content);
}

int main()
{
    // Create some list elements
    int content1 = 10;
    int content2 = 20;
    int content3 = 30;

    t_list *elem1 = ft_lstnew(&content1);
    t_list *elem2 = ft_lstnew(&content2);
    t_list *elem3 = ft_lstnew(&content3);

    // Link the elements together
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = NULL;

    // Apply ft_lstmap to the list to add 1 to each element
    t_list *mapped_list = ft_lstmap(elem1, &add_one, &del_int);

    // Print the mapped list
    while (mapped_list != NULL)
    {
        printf("%d\n", *(int *)(mapped_list->content));
        mapped_list = mapped_list->next;
    }

    // Free the memory allocated for the original list and the mapped list
    ft_lstclear(&elem1, &del_int);
    ft_lstclear(&mapped_list, &del_int);

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:21:29 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/26 15:58:48 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Create a new node with the given content
t_stack	*lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = node;
	node->prev = node;
	return (node);
}

// Add a new node to the end of the list
void	lstappend(t_stack **lst, t_stack *new_list)
{
	t_stack	*last;

	if (!lst || !new_list)
		return ;
	if (!*lst)
		*lst = new_list;
	else
	{
		last = *lst;
		while (last->next != *lst)
			last = last->next;
		last->next = new_list;
		new_list->prev = last;
		new_list->next = *lst;
		(*lst)->prev = new_list;
	}
}

// Counts the number of nodes in a list
size_t	lstsize(t_stack *lst)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = lst;
	while (true)
	{
		current = current->next;
		count++;
		if (current == lst)
			break ;
	}
	return (count);
}

// Clear the list
void	lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp->next != *lst)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	*lst = NULL;
}

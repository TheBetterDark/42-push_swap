/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:34:53 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/20 21:36:00 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Finds the node with the cheapest push cost
t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (true)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (NULL);
}

// Finds the node with the smallest number
t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = stack;
	current = stack;
	while (true)
	{
		if (current->content < min_node->content)
			min_node = current;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (min_node);
}

// Finds the node with the largest number
t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = stack;
	current = stack;
	while (true)
	{
		if (current->content > max_node->content)
			max_node = current;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (max_node);
}

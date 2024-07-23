/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:45:55 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:44:36 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_target_node(t_stack *current_1, t_stack *stack_2);

// Set the target node for each node in stack_a
void	set_target_node_b(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*current_1;

	if (!stack_1)
		return ;
	current_1 = stack_1;
	while (true)
	{
		find_target_node(current_1, stack_2);
		current_1 = current_1->next;
		if (current_1 == stack_1)
			break ;
	}
}

// Find the target node for a node in stack_a
static void	find_target_node(t_stack *current_1, t_stack *stack_2)
{
	t_stack	*current_2;
	t_stack	*target_node;
	long	closest_smaller;

	closest_smaller = LONG_MAX;
	target_node = NULL;
	current_2 = stack_2;
	while (true)
	{
		if (current_2->content > current_1->content
			&& current_2->content < closest_smaller)
		{
			closest_smaller = current_2->content;
			target_node = current_2;
		}
		current_2 = current_2->next;
		if (current_2 == stack_2)
			break ;
	}
	if (closest_smaller == LONG_MAX)
		current_1->target_node = find_min(stack_2);
	else
		current_1->target_node = target_node;
}

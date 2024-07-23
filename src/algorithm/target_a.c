/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:21:20 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:45:00 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_target_node(t_stack *stack_1, t_stack *stack_2);

// Set the target node for each node in stack_a
void	set_current_index(t_stack *stack)
{
	t_stack	*current;
	int		median;
	int		i;

	if (!stack)
		return ;
	i = 0;
	median = lstsize(stack) / 2;
	current = stack;
	while (true)
	{
		current->index = i;
		if (i < median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
		if (current == stack)
			break ;
	}
}

// Set the target node for each node in stack_a
void	cost_analysis(t_stack **stacks)
{
	t_stack	*current;
	int		size_a;
	int		size_b;

	size_a = lstsize(stacks[0]);
	size_b = lstsize(stacks[1]);
	current = stacks[0];
	while (true)
	{
		current->push_cost = current->index;
		if (!current->above_median)
			current->push_cost = size_a - current->index;
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += size_b - current->target_node->index;
		current = current->next;
		if (current == stacks[0])
			break ;
	}
}

// Set the target node for each node in stack_a
void	set_target_node_a(t_stack *stack_1, t_stack *stack_2)
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

// Finds the node with the cheapest push cost
void	set_cheapest_node(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cheapest_node;
	long	cheapest_cost;

	current = stack;
	cheapest_node = NULL;
	cheapest_cost = LONG_MAX;
	while (true)
	{
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

// Find the target node for a node in stack_a
static void	find_target_node(t_stack *current_1, t_stack *stack_2)
{
	t_stack	*current_2;
	t_stack	*target_node;
	long	closest_smaller;

	closest_smaller = LONG_MIN;
	target_node = NULL;
	current_2 = stack_2;
	while (true)
	{
		if (current_2->content < current_1->content
			&& current_2->content > closest_smaller)
		{
			closest_smaller = current_2->content;
			target_node = current_2;
		}
		current_2 = current_2->next;
		if (current_2 == stack_2)
			break ;
	}
	if (closest_smaller == LONG_MIN)
		current_1->target_node = find_max(stack_2);
	else
		current_1->target_node = target_node;
}

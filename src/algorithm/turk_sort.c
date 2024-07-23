/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:10:03 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:44:06 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_min_to_top(t_stack **stacks);
static void	init_a(t_stack **stacks);
static void	init_b(t_stack **stacks);

// Turkish sort algorithm
void	turk_sort(t_stack **stacks)
{
	if (lstsize(stacks[0]) > 3 && !is_sorted(stacks[0]))
		push_b(stacks);
	if (lstsize(stacks[0]) > 3 && !is_sorted(stacks[0]))
		push_b(stacks);
	while (lstsize(stacks[0]) > 3 && !is_sorted(stacks[0]))
	{
		init_a(stacks);
		push_a_to_b(stacks);
	}
	sort_three(stacks);
	while (stacks[1])
	{
		init_b(stacks);
		push_b_to_a(stacks);
	}
	set_current_index(stacks[0]);
	move_min_to_top(stacks);
}

// Move the node with the smallest number to the top of stack_a
static void	move_min_to_top(t_stack **stacks)
{
	t_stack	*min_node;

	min_node = find_min(stacks[0]);
	while (stacks[0]->content != min_node->content)
	{
		if (min_node->above_median)
			rotate_a(stacks);
		else
			reverse_rotate_a(stacks);
	}
}

// Prepares stack_a for sorting by indexing and analyzing costs
static void	init_a(t_stack **stacks)
{
	set_current_index(stacks[0]);
	set_current_index(stacks[1]);
	set_target_node_a(stacks[0], stacks[1]);
	cost_analysis(stacks);
	set_cheapest_node(stacks[0]);
}

// Prepares stack_b for operations by indexing elements
static void	init_b(t_stack **stacks)
{
	set_current_index(stacks[0]);
	set_current_index(stacks[1]);
	set_target_node_b(stacks[1], stacks[0]);
}

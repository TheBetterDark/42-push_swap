/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:26:00 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/23 15:45:39 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate_a_b(t_stack **stacks, t_stack *cheapest);
static void	rotate_a_b(t_stack **stacks, t_stack *cheapest);
static void	rotate_to_new_head(t_stack **stacks, t_stack *new_head,
				char stack_name);

// Push the cheapest node from stack A to stack B
void	push_a_to_b(t_stack **stacks)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(stacks[0]);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_a_b(stacks, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_a_b(stacks, cheapest);
	rotate_to_new_head(stacks, cheapest, 'a');
	rotate_to_new_head(stacks, cheapest->target_node, 'b');
	push_b(stacks);
}

// Push the cheapest node from stack B to stack A
void	push_b_to_a(t_stack **stacks)
{
	rotate_to_new_head(stacks, stacks[1]->target_node, 'a');
	push_a(stacks);
}

// Set the target node for the cheapest node in stack A
static void	rotate_a_b(t_stack **stacks, t_stack *cheapest)
{
	while (stacks[1] != cheapest->target_node && stacks[0] != cheapest)
		rotate_ab(stacks);
	set_current_index(stacks[0]);
	set_current_index(stacks[1]);
}

// Set the target node for the cheapest node in stack B
static void	reverse_rotate_a_b(t_stack **stacks, t_stack *cheapest)
{
	while (stacks[1] != cheapest->target_node && stacks[0] != cheapest)
		reverse_rotate_ab(stacks);
	set_current_index(stacks[0]);
	set_current_index(stacks[1]);
}

// Rotate the stack to the new head
static void	rotate_to_new_head(t_stack **stacks, t_stack *new_head,
		char stack_name)
{
	if (stack_name == 'a')
	{
		while (stacks[0] != new_head)
		{
			if (new_head->above_median)
				rotate_a(stacks);
			else
				reverse_rotate_a(stacks);
		}
	}
	else if (stack_name == 'b')
	{
		while (stacks[1] != new_head)
		{
			if (new_head->above_median)
				rotate_b(stacks);
			else
				reverse_rotate_b(stacks);
		}
	}
}

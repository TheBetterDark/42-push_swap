/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:35:40 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:45:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Sort three nodes in stack_a
void	sort_three(t_stack **stacks)
{
	t_stack	*max_node;

	max_node = find_max(stacks[0]);
	if (max_node == stacks[0])
		rotate_a(stacks);
	else if (stacks[0]->next == max_node)
		reverse_rotate_a(stacks);
	if (stacks[0]->content > stacks[0]->next->content)
		swap_a(stacks);
}

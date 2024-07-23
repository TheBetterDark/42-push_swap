/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:06:24 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:45:13 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Check if the stack is sorted in ascending order
bool	is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		last;

	current = stack;
	last = stack->content;
	while (true)
	{
		if (last > current->content)
			return (false);
		last = current->content;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (true);
}

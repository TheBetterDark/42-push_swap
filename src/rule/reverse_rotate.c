/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:00:29 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/16 01:33:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rules:
**
**	reverse_rotate_a: Shift down all elements of stack a by 1.
**	The last element becomes the first one.
**
**	reverse_rotate_b: Shift down all elements of stack b by 1.
**	The last element becomes the first one.
**
**	reverse_rotate_ab: reverse_rotate_a and reverse_rotate_b at the same time.
*/

#include "../../includes/push_swap.h"

// Sets the head of stack A to the previous element
void	reverse_rotate_a(t_stack **stacks)
{
	if (!stacks[0])
		return ;
	stacks[0] = stacks[0]->prev;
	ft_printf("rra\n");
}

// Sets the head of stack B to the previous element
void	reverse_rotate_b(t_stack **stacks)
{
	if (!stacks[1])
		return ;
	stacks[1] = stacks[1]->prev;
	ft_printf("rrb\n");
}

// Sets the head of stack A to the previous element
void	reverse_rotate_ab(t_stack **stacks)
{
	stacks[0] = stacks[0]->prev;
	stacks[1] = stacks[1]->prev;
	ft_printf("rrr\n");
}

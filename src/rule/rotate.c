/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:59:23 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/16 01:33:40 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rules:
**
**	rotate_a: Shift up all elements of stack a by 1.
**	The first element becomes the last one.
**
**	rotate_b: Shift up all elements of stack b by 1.
**	The first element becomes the last one.
**
**	rotate_ab: rotate_a and rotate_b at the same time.
*/

#include "../../includes/push_swap.h"

// Sets the head of stack A to the next element
void	rotate_a(t_stack **stacks)
{
	if (!stacks[0])
		return ;
	stacks[0] = stacks[0]->next;
	ft_printf("ra\n");
}

// Sets the head of stack B to the next element
void	rotate_b(t_stack **stacks)
{
	if (!stacks[1])
		return ;
	stacks[1] = stacks[1]->next;
	ft_printf("rb\n");
}

// Sets the head of stack A to the next element
void	rotate_ab(t_stack **stacks)
{
	if (stacks[0])
		stacks[0] = stacks[0]->next;
	if (stacks[1])
		stacks[1] = stacks[1]->next;
	ft_printf("rr\n");
}

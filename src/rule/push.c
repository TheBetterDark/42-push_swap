/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:24:43 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 01:43:35 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rules:
**
**	push_a: Take the first element at the top of b and put it at the top of a.
**	Do nothing if b is empty.
**
**	push_b: Take the first element at the top of a and put it at the top of b.
**	Do nothing if a is empty.
*/

#include "../../includes/push_swap.h"

static void	push(t_stack **stack_from, t_stack **stack_to);

// Move the first element from stack_b to stack_a as head of stack_a
void	push_a(t_stack **stacks)
{
	if (stacks[1] == NULL)
		return ;
	push(&stacks[1], &stacks[0]);
	ft_printf("pa\n");
}

// Move the first element from stack_a to stack_b as head of stack_b
void	push_b(t_stack **stacks)
{
	if (stacks[0] == NULL)
		return ;
	push(&stacks[0], &stacks[1]);
	ft_printf("pb\n");
}

// Move the first element from stack_from to stack_to as head of stack_to
static void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*first_element;

	first_element = *stack_from;
	if (first_element->next == first_element)
		*stack_from = NULL;
	else
	{
		*stack_from = first_element->next;
		first_element->prev->next = first_element->next;
		first_element->next->prev = first_element->prev;
	}
	if ((*stack_to) == NULL)
	{
		first_element->next = first_element;
		first_element->prev = first_element;
	}
	else
	{
		first_element->next = *stack_to;
		first_element->prev = (*stack_to)->prev;
		(*stack_to)->prev->next = first_element;
		(*stack_to)->prev = first_element;
	}
	*stack_to = first_element;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:42:27 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/26 16:20:27 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rules:
**
**	swap_a: Swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements.
**
**	swap_b: Swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements.
**
**	swap_ab : swap_a and swap_b at the same time.
*/

#include "../../includes/push_swap.h"

static void	swap(t_stack **head);

// Swaps the first two elements of stack A
void	swap_a(t_stack **stacks)
{
	if (!stacks[0] || !stacks[0]->next)
		return ;
	swap(&stacks[0]);
	ft_printf("sa\n");
}

// Swaps the first two elements of stack B
void	swap_b(t_stack **stacks)
{
	if (!stacks[1] || !stacks[1]->next)
		return ;
	swap(&stacks[1]);
	ft_printf("sb\n");
}

// Swaps the first two elements of both stacks
void	swap_ab(t_stack **stacks)
{
	if (stacks[0] && stacks[0]->next)
		swap(&stacks[0]);
	if (stacks[1] && stacks[1]->next)
		swap(&stacks[1]);
	ft_printf("ss\n");
}

// Swaps the first two elements of a stack
static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (lstsize(*head) == 2)
	{
		*head = (*head)->next;
		return ;
	}
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (second->prev != first)
		second->prev->next = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

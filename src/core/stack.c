/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:12:25 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 20:34:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>

static bool	validate_syntax(char *arg);
static bool	validate_duplicates(t_stack *stack, int number);

// Initialize the stacks with the given arguments
t_stack	**initalize_stacks(char *numbers[])
{
	t_stack	**stacks;
	long	n;
	int		i;

	stacks = NULL;
	i = 0;
	stacks = malloc(sizeof(t_stack *) * 2);
	if (stacks == NULL)
		handle_error(NULL, "Memory Allocation Failure");
	stacks[0] = NULL;
	while (numbers[i])
	{
		if (!validate_syntax(numbers[i]))
			handle_error(stacks, "Invalid Argument");
		n = atol(numbers[i]);
		if (n > INT_MAX || n < INT_MIN)
			handle_error(stacks, "INT_MAX or INT_MIN Overflow");
		if (!validate_duplicates(stacks[0], n))
			handle_error(stacks, "Duplicate Argument");
		lstappend(&stacks[0], lstnew((int)n));
		i++;
	}
	stacks[1] = NULL;
	return (stacks);
}

// Free the memory allocated for the stacks
void	cleanup_stacks(t_stack **stacks)
{
	if (!stacks)
		return ;
	if (stacks[0] != NULL)
		lstclear(&stacks[0]);
	if (stacks[1] != NULL)
		lstclear(&stacks[1]);
	free(stacks);
}

// Check if the argument is a valid number and in the correct format
static bool	validate_syntax(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

// Check for duplicate numbers in the stack
static bool	validate_duplicates(t_stack *stack, int number)
{
	t_stack	*current;

	if (stack == NULL)
		return (true);
	current = stack;
	while (current->next != stack)
	{
		if (current->content == number)
			return (false);
		current = current->next;
	}
	return (true);
}

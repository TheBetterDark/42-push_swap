/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:02:35 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 02:45:26 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Standard library headers

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// External libraries

# include "../libs/libft/includes/libft.h"

// Struct declarations

typedef struct s_stack
{
	int				index;
	bool			above_median;

	int				push_cost;
	bool			cheapest;

	struct s_stack	*target_node;

	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// Function declarations

void				handle_error(t_stack **stacks, char *info);
t_stack				**initalize_stacks(char *numbers[]);
void				cleanup_stacks(t_stack **stacks);

void				push_a(t_stack **stacks);
void				push_b(t_stack **stacks);

void				swap_a(t_stack **stacks);
void				swap_b(t_stack **stacks);
void				swap_ab(t_stack **stacks);

void				rotate_a(t_stack **stacks);
void				rotate_b(t_stack **stacks);
void				rotate_ab(t_stack **stacks);

void				reverse_rotate_a(t_stack **stacks);
void				reverse_rotate_b(t_stack **stacks);
void				reverse_rotate_ab(t_stack **stacks);

bool				is_sorted(t_stack *stack);
void				turk_sort(t_stack **stacks);
void				sort_three(t_stack **stacks);
void				cost_analysis(t_stack **stacks);
void				set_cheapest_node(t_stack *stack);
void				set_current_index(t_stack *stack);
void				set_target_node_a(t_stack *stack_1, t_stack *stack_2);
void				set_target_node_b(t_stack *stack_1, t_stack *stack_2);
void				push_a_to_b(t_stack **stacks);
void				push_b_to_a(t_stack **stacks);

t_stack				*lstnew(int content);
void				lstappend(t_stack **lst, t_stack *new_list);
size_t				lstsize(t_stack *lst);
void				lstclear(t_stack **lst);

t_stack				*find_cheapest(t_stack *stack);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);

#endif

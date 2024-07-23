/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:01:58 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/18 17:46:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Handle the error and free the memory allocated for the stacks
void	handle_error(t_stack **stacks, char *info)
{
	ft_printf("\033[0;31mError: %s\n\033[0m", info);
	cleanup_stacks(stacks);
	exit(EXIT_FAILURE);
}

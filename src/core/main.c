/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:02:24 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/23 20:05:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	cleanup(t_stack **stacks, char **split);
static void	check_args(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_stack	**stacks;
	char	**split;

	split = NULL;
	check_args(argc, argv);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		stacks = initalize_stacks(split);
	}
	else
		stacks = initalize_stacks(argv + 1);
	if (!stacks)
		handle_error(NULL, "Failed to Initalize Stacks");
	if (!is_sorted(stacks[0]))
	{
		if (lstsize(stacks[0]) == 2)
			swap_a(stacks);
		else if (lstsize(stacks[0]) == 3)
			sort_three(stacks);
		else
			turk_sort(stacks);
	}
	cleanup(stacks, split);
}

static void	check_args(int argc, char *argv[])
{
	if (argc == 1 || (argc > 2 && !argv[1][0]) || (argc == 2
		&& (ft_strlen(argv[1]) == 0 || ft_strtrim(argv[1], " ")[0] == '\0')))
	{
		ft_printf("Usage: push_swap 2 1 3 5 4 || push_swap \"2 1 3 5 4\"");
		exit(EXIT_FAILURE);
	}
}

static void	cleanup(t_stack **stacks, char **split)
{
	int	i;

	cleanup_stacks(stacks);
	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	exit(EXIT_SUCCESS);
}

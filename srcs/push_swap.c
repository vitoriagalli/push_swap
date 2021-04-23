/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 22:43:50 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_push_swap(t_stacks *stacks, t_node **max)
{
	clear_stacks(stacks);
	ft_nodeclear(max);
	exit(EXIT_FAILURE);
}

static void	sort_list_of_many(t_stacks *stacks)
{
	push_to_b(stacks);
	push_to_a(stacks);
}

static void	sort_stack(t_stacks *stacks)
{
	if (stacks->a.size == 2)
		sort_list_of_two(stacks);
	if (stacks->a.size == 3)
		sort_list_of_three(stacks);
	else if (stacks->a.size == 5)
		sort_list_of_five(stacks);
	else
		sort_list_of_many(stacks);
}

static void	game_on(t_stacks *stacks)
{
	bool	sorted;

	sorted = false;
	while (!sorted)
	{
		sort_stack(stacks);
		sorted = is_sorted(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**argv_split;

	argv_split = unify_args(argc, argv);
	validate_args(argc, argv_split);
	build_stacks(argv_split, &stacks);
	ft_array_clear((void **)argv_split);
	game_on(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

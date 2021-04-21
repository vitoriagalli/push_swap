/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 00:23:35 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// ft_printf("%i\n", stacks->n_op);
}

static void	game_on(t_stacks *stacks)
{
	bool	sorted;

	while (true)
	{
		sort_stack(stacks);
		sorted = is_sorted(stacks);
		if (sorted == true)
		// if (sorted = true)
			return ;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**argv_split;

	argv_split = unify_args(argc, argv);
	validate_args(argc, argv_split);
	build_stacks(argv_split, &stacks);
	ft_array_clear(argv_split);
	game_on(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

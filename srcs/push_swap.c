/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/15 21:06:55 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	game_on(t_stacks *stacks)
{
	bool	sort;

	sort = is_sorted(stacks);
	while (sort == false)
	{
		// insertion_sort(stacks);
		// sort_list_of_tree(stacks);
		sort_list_of_five(stacks);
		sort = is_sorted(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	validate_args(argc, argv);
	build_stacks(argc, argv, &stacks);
	game_on(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

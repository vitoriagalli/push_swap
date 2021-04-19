/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/20 00:03:09 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	game_on(t_stacks *stacks)
{
	// bool	sort;

	// sort = is_sorted(stacks);
	// while (sort == false)
	// {
		// insertion_sort(stacks);
		// sort_list_of_tree(stacks);
		// sort_list_of_five(stacks);


		sort_compare(stacks);
		// sort_another_try(stacks);

	// 	sort = is_sorted(stacks);
	// }

	ft_printf("%i\n", stacks->n_op);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 17:52:48 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_push_swap(t_stacks *stacks)
{
	clear_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	push_to_stack_b(t_stacks *stacks)
{
	int	init_size;

	init_size = stacks->a.size;
	while (init_size)
	{
		if ((t_stacks *)(stacks->a.head)->keep_a)
			call_operation("ra", stacks);
		else
			call_operation("pb", stacks);
		init_size--;
	}
}

void	push_to_stack_a(t_stacks *stacks)
{
	t_actions	*def;

	def = NULL;
	def = ft_calloc(1, sizeof(t_actions));
	while (stacks->b.head != NULL)
	{
		find_smallest_action_to_push_to_a(stacks, def);
		attribute_operations(def);
		operate_actions(stacks, def);
		ft_bzero(def, sizeof(t_actions));
	}
	free(def);
}

static void	algorithm(t_stacks *stacks)
{
	index_elements_in_stack_a(&stacks->a);
	markup_head(&stacks->a);
	push_to_stack_b(stacks);
	push_to_stack_a(stacks);
	align_stack_a(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**argv_split;

	argv_split = unify_args(argc, argv);
	validate_args(argc, argv_split);
	build_stacks(argv_split, &stacks);
	ft_array_clear((void **)argv_split);
	algorithm(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

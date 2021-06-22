/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 15:19:54 by vscabell         ###   ########.fr       */
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

void	align_stack_a(t_stacks *stacks)
{
	int		min;
	int		i;
	t_node	*tmp;
	char	*op;

	i = 1;
	tmp = stacks->a.head;
	min = min_value(tmp);
	while (tmp->numb != min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (stacks->a.size/2))
		op = "ra";
	else
		op = "rra";

	while (stacks->a.head->numb != min)
		call_operation(op, stacks);
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

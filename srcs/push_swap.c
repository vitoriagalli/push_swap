/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/14 02:08:19 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
}

size_t	get_posit_min_value(t_stack *a)
{
	t_list		*tmp;
	int			min;
	size_t		posit;
	size_t		i;

	i = 0;
	posit = 0;
	min = 2147483647;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->numb < min)
		{
			min = tmp->numb;
			posit = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (posit);
}

void	push_min_value_to_top_of_stack(t_stacks *stacks, size_t posit)
{
	size_t	i;

	i = 0;
	while (i < posit)
	{
		call_operation("ra", stacks);
		i++;
	}
}

void	calculate_opperations(t_stacks *stacks)
{
	size_t	posit;
	size_t	size;

	size = ft_lstsize(stacks->a.head);
	while (size > 0)
	{
		posit = get_posit_min_value(&stacks->a);
		push_min_value_to_top_of_stack(stacks, posit);
		call_operation("pb", stacks);
		size--;
	}
	size = ft_lstsize(stacks->b.head);
	while (size > 0)
	{
		call_operation("pa", stacks);
		size--;
	}
}

void	game_on(t_stacks *stacks)
{
	bool	sort;

	sort = is_sorted(stacks);
	while (sort == false)
	{
		calculate_opperations(stacks);
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

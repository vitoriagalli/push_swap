/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 21:29:57 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static bool	ascending(int a, int b)
{
	return (a > b);
}

static bool	descending(int a, int b)
{
	return (a < b);
}

static void	sort_nodes_by_posit_and_get_op(char **op, t_node **max)
{
	if ((*max)->top_half)
	{
		*op = "rb";
		sort_nodes_by_posit(max, ascending);
	}
	else
	{
		*op = "rrb";
		sort_nodes_by_posit(max, descending);
	}
}

static size_t	atribute_max_values(t_node **max, t_stack *stack, int limit)
{
	t_node		*new;
	bool		max_top_half;
	int			val_max;
	int			i;

	i = 0;
	val_max = MAX_INT;
	while (i < limit)
	{
		new = ft_nodenew(stack, val_max);
		if (!new)
			return (-1);
		if (i == 0)
			max_top_half = new->top_half;
		else if (new->top_half != max_top_half || new->value == MIN_INT)
		{
			free(new);
			return (i);
		}
		ft_nodeadd_back(max, new);
		val_max = new->value;
		i++;
	}
	return (i);
}

void	push_to_a(t_stacks *stacks)
{
	t_node	*max;
	char	*op;
	int		values_to_push_size;

	op = NULL;
	while (stacks->b.head)
	{
		max = NULL;

		values_to_push_size = atribute_max_values(&max, &stacks->b, 3);
		if (values_to_push_size == -1)
			exit_push_swap(stacks, &max);
		sort_nodes_by_posit_and_get_op(&op, &max);
		if (values_to_push_size == 1)
			rotate_and_push_value(stacks, op, max->value);
		else if (values_to_push_size == 2)
			rotate_and_push_two_values(stacks, op, max);
		else
			rotate_and_push_three_values(stacks, op, max);
		// else if (lst_size == 4)
		// 	rotate_and_push_four_values(stacks, op, max);

		ft_nodeclear(&max);
	}
}

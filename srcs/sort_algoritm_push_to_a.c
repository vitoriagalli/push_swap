/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:33 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	atribute_max_values(t_node **max, t_stack *stack)
{
	bool		max_top_half;
	t_node		*new;
	int			val_max;
	int			i;

	i = 0;
	val_max = MAX_INT;
	while (i < 2)
	// while (i < 5)
	{
		new = ft_nodenew(stack, val_max);


		if (!new)
			return (0); // exit
		if (i == 0)
			max_top_half = new->top_half;
		else if (new->top_half != max_top_half)
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
	size_t	lst_size;

	op = NULL;
	while (stacks->b.head)
	{
		max = NULL;
		lst_size = atribute_max_values(&max, &stacks->b);

		if (max && max->next && max->next->value == MIN_INT)
		{
			// liberar a cadeira de nodes
			lst_size--;
			max->next = NULL;
		}


		if (max->top_half)
		{
			op = "rb";
			sort_nodes_by_posit(&max, ascending);
		}
		else
		{
			op = "rrb";
			sort_nodes_by_posit(&max, descending);
		}


		// ft_printf("%i\n", lst_size);
		if (lst_size == 1)
			rotate_and_push_value(stacks, op, max->value);
		else if (lst_size == 2)
			rotate_and_push_two_values(stacks, op, max);


		// return ;

	}
}

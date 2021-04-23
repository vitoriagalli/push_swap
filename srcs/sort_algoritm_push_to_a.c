/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 14:20:42 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_posit_value(t_stack *b, int numb)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = b->head;
	while (tmp)
	{
		if (tmp->numb == numb)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (b->size + 1);
}

static void	atribute_max_values(t_node **max, t_stack *stack)
{
	t_node	*new;
	int		val_max;
	int		i;

	i = 0;
	val_max = MAX_INT;
	while (i < 5)
	{
		new = ft_nodenew(stack, val_max);
		ft_nodeadd_back(max, new);
		val_max = new->value;
		i++;
	}
}

void	push_to_a(t_stacks *stacks)
{
	t_node	*max;
	char	*op;

	max = NULL;
	op = NULL;
	while (stacks->b.head)
	{
		atribute_max_values(&max, &stacks->b);
		sort_nodes_by_posit(&max);

		return ;

		// if (n->max.top_half)
		// 	op = "rb";

	}
}

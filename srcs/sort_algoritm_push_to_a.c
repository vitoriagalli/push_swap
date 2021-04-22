/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 00:28:53 by vscabell         ###   ########.fr       */
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

static void	atribute_max_values(t_nodes *n, t_stack *stack)
{
	n->max.value = get_max_value_but_n(stack, MAX_INT);
	n->max.posit = get_posit_value(stack, n->max.value);
	n->second_max.value = get_max_value_but_n(stack, n->max.value);
	n->second_max.posit = get_posit_value(stack, n->second_max.value);
	n->third_max.value = get_max_value_but_n(stack, n->second_max.value);
	n->third_max.posit = get_posit_value(stack, n->third_max.value);
}

static void	rotate_and_push_two_values(t_stacks *stacks, char *op, t_nodes *n)
{
	int	first_to_push;
	int	second_to_push;

	if ((n->max.top_half && n->max.posit < n->second_max.posit)
		|| (!n->max.top_half && n->max.posit > n->second_max.posit))
	{
		first_to_push = n->max.value;
		second_to_push = n->second_max.value;
	}
	else
	{
		first_to_push = n->second_max.value;
		second_to_push = n->max.value;
	}
	rotate_and_push_value(stacks, op, first_to_push);
	rotate_and_push_value(stacks, op, second_to_push);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

void	push_to_a(t_stacks *stacks)
{
	t_nodes	n;
	char	*op;

	while (stacks->b.head)
	{
		atribute_max_values(&n, &stacks->b);
		n.max.top_half = n.max.posit < (size_t)(stacks->b.size / 2);
		n.second_max.top_half = n.second_max.posit < (size_t)
			(stacks->b.size / 2);
		n.third_max.top_half = n.third_max.posit < (size_t)(stacks->b.size / 2);
		if (n.max.top_half)
			op = "rb";
		else
			op = "rrb";
		if (!(n.second_max.posit < stacks->b.size)
			|| (n.max.top_half ^ n.second_max.top_half)
			|| n.max.value == n.second_max.value)
			rotate_and_push_value(stacks, op, n.max.value);
		else if (!(n.third_max.posit < stacks->b.size)
			|| (n.max.top_half ^ n.third_max.top_half))
			rotate_and_push_two_values(stacks, op, &n);
		else
			rotate_and_push_three_values(stacks, op, &n);
	}
}

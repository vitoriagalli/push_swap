/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_values_to_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:45:36 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 22:18:23 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_push_value(t_stacks *stacks, char *op, int value)
{
	while (stacks->b.head && stacks->b.head->numb != value)
		call_operation(op, stacks);
	call_operation("pa", stacks);
}

void	rotate_and_push_two_values(t_stacks *stacks, char *op, t_node *max)
{
	rotate_and_push_value(stacks, op, max->value);
	rotate_and_push_value(stacks, op, max->next->value);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

void	rotate_and_push_three_values(t_stacks *stacks, char *op, t_node *max)
{
	rotate_and_push_value(stacks, op, max->value);
	rotate_and_push_value(stacks, op, max->next->value);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
	if (max->next->next->value > max->value
		&& max->next->next->value > max->next->value)
	{
		while (stacks->b.head->numb != max->next->next->value)
			call_operation(op, stacks);
		call_operation("ra", stacks);
		call_operation("pa", stacks);
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else
	{
		rotate_and_push_value(stacks, op, max->next->next->value);
		if (stacks->a.head && stacks->a.head->next
			&& stacks->a.head->numb > stacks->a.head->next->numb)
			call_operation("sa", stacks);
	}
}

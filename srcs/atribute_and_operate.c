/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atribute_and_operate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:42:48 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/23 01:18:53 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** according to the info stored in the struct, assign the operations
** if both nodes are in the same half, optimize the operations (rr or rrr)
** and recalculate the op in each stack
*/
void	attribute_operations(t_actions *def)
{
	if (!(def->a.top ^ def->b.top))
	{
		def->n_op_same = min_value(def->a.n_op, def->b.n_op);
		def->b.n_op -= def->n_op_same;
		def->a.n_op -= def->n_op_same;
	}
	if (def->a.top == true)
	{
		ft_memmove((char *)&def->a.op, "ra", 4);
		ft_memmove((char *)&def->op_same, "rr", 4);
	}
	else
	{
		ft_memmove((char *)&def->a.op, "rra", 4);
		ft_memmove((char *)&def->op_same, "rrr", 4);
	}
	if (def->b.top == true)
		ft_memmove((char *)&def->b.op, "rb", 4);
	else
		ft_memmove((char *)&def->b.op, "rrb", 4);
}

/*
** call the operations according to the best perform stored in def
*/
void	operate_actions(t_stacks *stacks, t_actions *def)
{
	while (def->n_op_same--)
		call_operation(def->op_same, stacks);
	while (def->a.n_op--)
		call_operation(def->a.op, stacks);
	while (def->b.n_op--)
		call_operation(def->b.op, stacks);
	call_operation("pa", stacks);
}

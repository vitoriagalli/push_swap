/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:28:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/23 14:11:40 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** optimizes op numb according to the position of the node in stack
** store info in the struct to use when assigning the operations
*/
void	calculate_n_op_stack(t_info *info)
{
	if (info->ind < (info->size / 2))
	{
		info->top = true;
		info->n_op = info->ind;
	}
	else
	{
		info->top = false;
		info->n_op = info->size - info->ind;
	}
}

/*
** add the number of operations needed in stack A and stack B
** if both nodes are in tha same half, optimize the operation
** ra and rb cant be replaced by rr, per exemple
*/
void	get_total_op(t_actions *tmp, t_actions *def)
{
	tmp->total = tmp->a.n_op + tmp->b.n_op;
	if (!(tmp->a.top ^ tmp->b.top))
		tmp->total -= min_value(tmp->a.n_op, tmp->b.n_op);
	if (tmp->total < def->total)
		ft_memmove(def, tmp, sizeof(t_actions));
}

/*
** check the position in stack A where to put a given value (stack B node)
** and count the number of operations needed in stack A for this
** add both to get the total value
*/
void	get_actions_in_stack_a(t_actions *tmp, t_actions *def,
	t_stacks *stacks, int value)
{
	t_node		*head;
	int			max;

	tmp->a.ind = 0;
	head = stacks->a.head;
	head->previous = ft_nodelast(head);
	max = get_max_value(head);
	while (head)
	{
		if ((head->numb > value && ((t_node *)(head->previous))->numb < value)
			|| (head->numb > value && ((t_node *)(head->previous))->numb == max)
			|| (head->numb < value
			&& ((t_node *)(head->previous))->numb == max && value > max))
			break ;
		head = head->next;
		(tmp->a.ind)++;
	}
	calculate_n_op_stack(&tmp->a);
	get_total_op(tmp, def);
}

/*
** iterate over stack B to find the node in stack A
** in wich combined with B operations, total the least number of operations
** def var is going to store the information needed to best perform
*/
void	find_smallest_action_to_push_to_a(t_stacks *stacks, t_actions *def)
{
	t_actions	tmp;
	t_node		*tmp_b;

	ft_bzero(&tmp, sizeof(t_actions));
	tmp.a.size = stacks->a.size;
	tmp.b.size = stacks->b.size;
	def->total = MAX_INT;
	tmp_b = stacks->b.head;
	while (tmp_b)
	{
		calculate_n_op_stack(&tmp.b);
		get_actions_in_stack_a(&tmp, def, stacks, tmp_b->numb);
		tmp_b = tmp_b->next;
		tmp.b.ind++;
	}
}

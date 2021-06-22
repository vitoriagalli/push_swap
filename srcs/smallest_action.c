/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:28:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 14:09:06 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodelast(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	calculate_n_op(t_info *info)
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

int		max_value(t_node *tmp)
{
	int	max;

	max = MIN_INT;
	while (tmp)
	{
		if (tmp->numb > max)
			max = tmp->numb;
		tmp = tmp->next;
	}
	return (max);
}

void	calculate_actions_in_stack_a(t_actions *tmp, t_actions *def,
	t_stacks *stacks, int value)
{
	t_node		*head;
	int			max;

	tmp->a.ind = 0;
	head = stacks->a.head;
	head->previous = ft_nodelast(head);
	max = max_value(head);
	while (head)
	{
		// ft_printf("%d %d\n", head->numb, value);
		if ((head->numb > value && ((t_node *)(head->previous))->numb < value)
			|| (head->numb > value && ((t_node *)(head->previous))->numb == max)
			|| (head->numb < value && head->numb == max))
			break ;
		head = head->next;
		(tmp->a.ind)++;
	}
	calculate_n_op(&tmp->a);
	tmp->total = tmp->a.n_op + tmp->b.n_op;
	if (tmp->total < def->total)
		ft_memmove(def, tmp, sizeof(t_actions));
}

void	find_smallest_action_to_push_to_a(t_stacks *stacks, t_actions *def)
{
	// t_actions	def;
	t_actions	tmp;
	t_node		*tmp_b;

	ft_bzero(&tmp, sizeof(t_actions));
	tmp.a.size = stacks->a.size;
	tmp.b.size = stacks->b.size;
	// ft_memmove(&def, &tmp, sizeof(t_actions));
	def->total = MAX_INT;
	tmp_b = stacks->b.head;
	while (tmp_b)
	{
		calculate_n_op(&tmp.b);
		calculate_actions_in_stack_a(&tmp, def, stacks, tmp_b->numb);
		tmp_b = tmp_b->next;
		tmp.b.ind++;
	}
	// ft_memmove(def, &def, sizeof(t_actions));
}

void	attribute_operations(t_actions *def)
{
	if (def->a.top == true)
		ft_memmove((char *)&def->a.op, "ra", 4);
	else
		ft_memmove((char *)&def->a.op, "rra", 4);
	if (def->b.top == true)
		ft_memmove((char *)&def->b.op, "rb", 4);
	else
		ft_memmove((char *)&def->b.op, "rrb", 4);
}

void	operate_actions(t_stacks *stacks, t_actions *def)
{
	while (def->a.n_op > 0)
	{
		call_operation(def->a.op, stacks);
		def->a.n_op--;
	}
	while (def->b.n_op > 0)
	{
		call_operation(def->b.op, stacks);
		def->b.n_op--;
	}
	call_operation("pa", stacks);
}

void	push_to_stack_a(t_stacks *stacks)
{
	t_actions	*def;
	int i = 0;

	def = NULL;
	def = ft_calloc(1, sizeof(t_actions));
	// for (int i = 0; i++; i < 100)
	while (stacks->b.head != NULL)
	{
		ft_printf("-- %i --\n", i); i++;
		find_smallest_action_to_push_to_a(stacks, def);
		attribute_operations(def);
		operate_actions(stacks, def);
		ft_bzero(def, sizeof(t_actions));
	}
	free(def);
}



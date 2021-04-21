/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:39:02 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/21 15:13:08 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
	(stacks->n_op)++;
}

int		get_max_value(t_stack *stack)
{
	t_list		*tmp;
	int			max;

	max = MIN_INT;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->numb > max)
			max = tmp->numb;
		tmp = tmp->next;
	}
	return (max);
}

int		get_min_value(t_stack *stack)
{
	t_list		*tmp;
	int			min;

	min = MAX_INT;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->numb < min)
			min = tmp->numb;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max_value_but_n(t_stack *stack, int n)
{
	t_list		*tmp;
	int			max;

	max = MIN_INT;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->numb > max && tmp->numb < n)
			max = tmp->numb;
		tmp = tmp->next;
	}
	return (max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:39:02 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/18 16:40:51 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max_value(t_stack *stack)
{
	t_list		*tmp;
	int			max;

	max = -2147483648;
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

	min = 2147483647;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->numb < min)
			min = tmp->numb;
		tmp = tmp->next;
	}
	return (min);
}

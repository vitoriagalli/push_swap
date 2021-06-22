/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:39:17 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 18:01:17 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
}

int	get_max_value(t_node *tmp)
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

int	get_min_value(t_node *tmp)
{
	int	min;

	min = MAX_INT;
	while (tmp)
	{
		if (tmp->numb < min)
			min = tmp->numb;
		tmp = tmp->next;
	}
	return (min);
}

int	min_value(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

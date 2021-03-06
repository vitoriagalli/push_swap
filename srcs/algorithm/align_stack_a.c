/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:37:28 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/23 00:29:15 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** call the necessary operation to make sure that the first node is the smallest
** if the minimum value is in the top bottom, operate 'ra', else operate 'rra'
*/
void	align_stack_a(t_stacks *stacks)
{
	int		min;
	size_t	i;
	t_node	*tmp;
	char	*op;

	i = 0;
	tmp = stacks->a.head;
	min = get_min_value(tmp);
	while (tmp->numb != min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (stacks->a.size / 2))
		op = "ra";
	else
		op = "rra";
	while (stacks->a.head->numb != min)
		call_operation(op, stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:59:46 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/13 01:33:54 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

static bool	sorted_stack(t_stack *stack)
{
	t_list	*tmp;

	if (!stack || !stack->head)
		return (false);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static bool	empty_stack(t_stack *stack)
{
	if (stack->size == 0 && !stack->head)
		return (true);
	return (false);
}

bool	is_sorted(t_stacks *stacks)
{
	if (sorted_stack(&stacks->a) && empty_stack(&stacks->b))
		return (true);
	return (false);
}

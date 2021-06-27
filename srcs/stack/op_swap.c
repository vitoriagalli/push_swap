/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:13 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/27 03:22:15 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

bool	swap(t_stack *stack)
{
	t_node	tmp;
	t_node	*node;
	t_node	*node_next;

	if (stack->size < 2 || !(stack->head) || !((t_node *)(stack->head)->next))
		return (true);
	node = stack->head;
	node_next = stack->head->next;
	tmp.numb = node->numb;
	tmp.index = node->index;
	tmp.keep_a = node->keep_a;
	node->numb = node_next->numb;
	node->index = node_next->index;
	node->keep_a = node_next->keep_a;
	node_next->numb = tmp.numb;
	node_next->index = tmp.index;
	node_next->keep_a = tmp.keep_a;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:17 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/20 23:36:03 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	rotate(t_stack *stack)
{
	t_node	*to_move;

	if (stack->size < 2 || !stack->head)
		return ;
	to_move = stack->head;
	stack->head = stack->head->next;
	to_move->next = NULL;
	ft_nodeadd_back(&stack->head, to_move);
}

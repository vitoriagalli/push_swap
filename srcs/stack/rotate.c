/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:17 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 15:34:26 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	t_list	*to_move;

	if (stack->size < 2 || !stack->head)
		return ;
	to_move = stack->head;
	stack->head = stack->head->next;
	to_move->next = NULL;
	ft_lstadd_back(&stack->head, to_move);
}

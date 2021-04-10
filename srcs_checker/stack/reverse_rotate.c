/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:20 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 15:34:33 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*to_move;
	int		i;

	if (stack->size < 2 || !stack->head)
		return ;
	i = 0;
	to_move = stack->head;
	while (to_move->next->next)
		to_move = to_move->next;
	to_move->next->next = stack->head;
	stack->head = to_move->next;
	to_move->next = NULL;
}

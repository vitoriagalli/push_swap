/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:27 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/27 03:22:49 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

bool	push(t_stack *to, t_stack *from)
{
	t_node	*to_move;

	if (from->size < 1 || !from->head)
		return (true);
	to_move = from->head;
	from->head = from->head->next;
	to_move->next = NULL;
	ft_nodeadd_front(&to->head, to_move);
	to->size++;
	from->size--;
	return (true);
}

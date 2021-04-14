/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:13 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/13 23:20:10 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	swap(t_stack *stack)
{
	t_list	*pt;

	pt = stack->head;
	if (stack->size < 2 || !pt || !pt->next)
		return ;
	pt->numb = pt->numb ^ pt->next->numb;
	pt->next->numb = pt->numb ^ pt->next->numb;
	pt->numb = pt->numb ^ pt->next->numb;
}

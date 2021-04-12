/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:13 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/12 02:49:08 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	swap(t_stack *stack)
{
	t_list	*pt;

	pt = stack->head;
	if (stack->size < 2 || !pt || !pt->next)
		return ;
	pt->content = (void *)((long)pt->content ^ (long)pt->next->content);
	pt->next->content = (void *)((long)pt->content ^ (long)pt->next->content);
	pt->content = (void *)((long)pt->content ^ (long)pt->next->content);
}

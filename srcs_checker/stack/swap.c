/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:13 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 03:03:32 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	t_list	*lst;

	lst = stack->head;
	if (stack->size < 2 || !lst || !lst->next)
		return ;
	lst->content = (int)lst->content ^ (int)lst->next->content;
	lst->next->content = (int)lst->content ^ (int)lst->next->content;
	lst->content = (int)lst->content ^ (int)lst->next->content;
}

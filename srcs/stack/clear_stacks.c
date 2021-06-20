/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:24:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 01:13:13 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

static void	ft_stack_clear(t_node **lst, size_t size)
{
	t_node	*to_free;
	size_t	i;

	to_free = *lst;
	if (!lst || !*lst)
		return ;
	i = 0;
	while (i < size)
	{
		*lst = to_free->next;
		free(to_free);
		to_free = *lst;
		i++;
	}
	*lst = NULL;
}

void	clear_stacks(t_stacks *stacks)
{
	ft_stack_clear(&stacks->a.head, stacks->a.size);
	ft_stack_clear(&stacks->b.head, stacks->b.size);
}

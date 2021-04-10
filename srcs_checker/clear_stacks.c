/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:24:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 16:26:27 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_stack_clear(t_list **lst, size_t size)
{
	t_list	*to_free;
	int		i;

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

void	clear_stacks(t_stacks stacks)
{
	ft_stack_clear(&stacks.a, stacks.a.size);
	ft_stack_clear(&stacks.b, stacks.b.size);
}

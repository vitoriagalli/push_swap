/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:17:31 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 01:25:10 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

t_node	*ft_nodenew(int numb)
{
	t_node	*elem;

	elem = ft_calloc(1, sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->numb = numb;
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}

void	ft_nodeadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->previous = tmp;
	}
}

void	ft_nodeadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->previous = new;
	}
	*lst = new;
}

void	build_stacks(char **argv, t_stacks *stacks)
{
	t_node	*new_node;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while (argv[stacks->a.size])
	{
		new_node = ft_nodenew(ft_atoi(argv[stacks->a.size]));
		if (!new_node)
			exit_program(stacks);
		ft_nodeadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}

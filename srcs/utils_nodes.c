/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:19:39 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 22:23:59 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_value_but_n(t_stack *stack, int n)
{
	t_list	*tmp;
	int		max;

	max = MIN_INT;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->numb > max && tmp->numb < n)
			max = tmp->numb;
		tmp = tmp->next;
	}
	return (max);
}

static size_t	get_posit_value(t_stack *b, int numb)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = b->head;
	while (tmp)
	{
		if (tmp->numb == numb)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (b->size + 1);
}

t_node	*ft_nodenew(t_stack *stack, int val_max)
{
	t_node	*max;

	max = malloc(sizeof(t_node));
	if (!max)
		return (NULL);
	max->value = get_max_value_but_n(stack, val_max);
	max->posit = get_posit_value(stack, max->value);
	max->top_half = max->posit < (size_t)(stack->size / 2);
	max->next = NULL;
	return (max);
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
	}
}

void	ft_nodeclear(t_node **lst)
{
	t_node	*to_free;

	if (!lst || !*lst)
		return ;
	to_free = *lst;
	while (to_free)
	{
		*lst = to_free->next;
		free(to_free);
		to_free = *lst;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:19:39 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 17:15:12 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeclear(t_node **lst)
{
	t_node	*to_free;

	to_free = *lst;
	if (!lst || !*lst)
		return ;
	while (to_free)
	{
		*lst = to_free->next;
		free(to_free);
		to_free = *lst;
	}
	*lst = NULL;
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

static void	ft_swap_node(t_node *n1, t_node *n2)
{
	int		int_aux;
	bool	bool_aux;

	int_aux = n1->posit;
	n1->posit = n2->posit;
	n2->posit = int_aux;
	int_aux = n1->value;
	n1->value = n2->value;
	n2->value = int_aux;
	bool_aux = n1->top_half;
	n1->top_half = n2->top_half;
	n2->top_half = bool_aux;

}

bool	ascending(int a, int b)
{
	return (a > b);
}

bool	descending(int a, int b)
{
	return (a < b);
}

void	sort_nodes_by_posit(t_node **begin_list, bool(*cmp)(size_t, size_t))
{
	t_node	*ptr1;
	t_node	*ptr2;

	if (!begin_list)
		return ;
	ptr1 = *begin_list;
	while (ptr1->next)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (cmp(ptr1->posit, ptr2->posit))
				ft_swap_node(ptr1, ptr2);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

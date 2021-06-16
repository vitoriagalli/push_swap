/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 22:23:30 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/08 03:50:24 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sort_nodes_by_posit(t_node **begin_list, bool(*cmp)(int, int))
{
	t_node	*ptr1;
	t_node	*ptr2;

	if (!begin_list)
		return 0;
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
	return (ptr1->posit);
}

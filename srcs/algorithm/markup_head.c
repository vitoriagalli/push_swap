/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:03:10 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/24 01:11:42 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** starting from the markup head, a node is going to be kept in the stack A
** if its index is bigger than the previous one.
** the nodes that do not satisfy this condition are marked as
** false and are pushed to the stack B
*/
static int	nodes_to_keep_a(t_stack *a, int markup_head, bool def)
{
	t_node	*tmp;
	int		index;
	int		num_keep_a;

	num_keep_a = 0;
	tmp = a->head;
	while (tmp->numb != markup_head)
		tmp = tmp->next;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->index > index)
		{
			if (def == true)
				tmp->keep_a = true;
			num_keep_a++;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (num_keep_a);
}

/*
** iterate over all the elements in stack A
** for each node as markup head, calculate the number of nodes kept in stack A
*/
static void	find_markup_head(t_stack *a)
{
	t_node	*tmp;
	int		num_keep_a;
	int		tmp_keep_a;

	num_keep_a = 0;
	tmp_keep_a = 0;
	tmp = a ->head;
	while (tmp)
	{
		tmp_keep_a = nodes_to_keep_a(a, tmp->numb, false);
		if (tmp_keep_a > num_keep_a)
		{
			a->markup_head = tmp->numb;
			num_keep_a = tmp_keep_a;
		}
		tmp = tmp->next;
	}
}

/*
** find the markup head
** the element that will keep the greatest amount of nodes in the stack A
** than tag the nodes according to the best perform markup head
*/
void	markup_head(t_stack *a)
{
	int	num_keep_a;

	find_markup_head(a);
	num_keep_a = nodes_to_keep_a(a, a->markup_head, true);
}

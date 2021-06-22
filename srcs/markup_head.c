/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:03:10 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 17:59:06 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_to_keep_a(t_stack *a, int markup_head, bool def)
{
	t_node	*tmp;
	int		index;
	int		num_keep_a;

	num_keep_a = 0;
	tmp = a ->head;
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

void	find_markup_head(t_stack *a)
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

void	markup_head(t_stack *a)
{
	int	num_keep_a;

	find_markup_head(a);
	num_keep_a = nodes_to_keep_a(a, a->markup_head, true);
}

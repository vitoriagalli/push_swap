/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:03:10 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 03:06:28 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_nodes_to_keep_a(t_stack *a, int markup_head)
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
		if (tmp->index == (index + 1))
		{
			num_keep_a++;
			index++;
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
		tmp_keep_a = check_nodes_to_keep_a(a, tmp->numb);
		if (tmp_keep_a > num_keep_a)
			a->markup_head_value = tmp->numb;
		tmp = tmp->next;
	}
}

void	prepare_stack_to_push(t_stack *a)
{
	t_node	*tmp;
	int		index;

	tmp = a->head;
	while (tmp->numb != a->markup_head_value)
		tmp = tmp->next;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->index == index)
		{
			tmp->keep_a = true;
			index++;
		}
		tmp = tmp->next;
	}
}

void	markup_head(t_stack *a)
{
	find_markup_head(a);
	prepare_stack_to_push(a);
}



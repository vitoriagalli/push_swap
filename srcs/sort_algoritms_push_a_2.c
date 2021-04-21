/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms_push_a_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:45:36 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/21 20:50:36 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_order_of_push(t_nodes *n, t_three *value_of_posit)
{
	if (n->max.posit < n->second_max.posit && n->max.posit < n->third_max.posit)
		value_of_posit->min = n->max.value;
	else if (n->second_max.posit < n->max.posit && n->second_max.posit < n->third_max.posit)
		value_of_posit->min = n->second_max.value;
	else
		value_of_posit->min = n->third_max.value;
	if (n->max.posit > n->second_max.posit && n->max.posit > n->third_max.posit)
		value_of_posit->max = n->max.value;
	else if (n->second_max.posit > n->max.posit && n->second_max.posit > n->third_max.posit)
		value_of_posit->max = n->second_max.value;
	else
		value_of_posit->max = n->third_max.value;
	if (!(value_of_posit->min == n->max.value || value_of_posit->max == n->max.value))
		value_of_posit->mid = n->max.value;
	else if (!(value_of_posit->min == n->second_max.value || value_of_posit->max == n->second_max.value))
		value_of_posit->mid = n->second_max.value;
	else
		value_of_posit->mid = n->third_max.value;

}

void	rotate_and_push_three_values(t_stacks *stacks, char *cmd, t_nodes *n)
{
	t_three	value_of_posit;
	int		first_to_push;
	int		second_to_push;
	int		third_to_push;

	get_order_of_push(n, &value_of_posit);
	if (n->max.top_half)
	{
		first_to_push = value_of_posit.min;
		second_to_push = value_of_posit.mid;
		third_to_push = value_of_posit.max;
	}
	else
	{
		first_to_push = value_of_posit.max;
		second_to_push = value_of_posit.mid;
		third_to_push = value_of_posit.min;
	}

	rotate_and_push_value(stacks, cmd, first_to_push);
	rotate_and_push_value(stacks, cmd, second_to_push);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);

	rotate_and_push_value(stacks, cmd, third_to_push);

	if (stacks->a.head && stacks->a.head->next && stacks->a.head->next->next
		&& stacks->a.head->numb > stacks->a.head->next->next->numb)
	{
		call_operation("pb", stacks);
		call_operation("ra", stacks);
		call_operation("pa", stacks);
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

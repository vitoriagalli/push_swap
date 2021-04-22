/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:27:05 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 02:55:34 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*................................*/
/*       SORT LIST OF FIVE        */
/*................................*/

static void	check_top_half(t_stacks *stacks, t_list *tmp)
{
	while (tmp)
	{
		if (tmp == stacks->a.head)
		{
			call_operation("pb", stacks);
			return ;
		}
		call_operation("ra", stacks);
	}
}

static void	check_bottom_half(t_stacks *stacks, t_list *tmp)
{
	while (tmp)
	{
		if (tmp == stacks->a.head)
		{
			call_operation("pb", stacks);
			return ;
		}
		call_operation("rra", stacks);
	}
}

static void	push_min_and_max_value_to_stack_b(t_stacks *stacks)
{
	t_list	*tmp_top;
	t_list	*tmp_bottom;
	int		min_value;
	int		max_value;
	int		chk;

	min_value = get_min_value(&stacks->a);
	max_value = get_max_value(&stacks->a);
	tmp_bottom = ft_lstlast(stacks->a.head);
	tmp_top = stacks->a.head;
	chk = 0;
	while (chk < 2 && tmp_top && tmp_bottom)
	{
		if (tmp_top->numb == min_value || tmp_top->numb == max_value)
		{
			chk++;
			check_top_half(stacks, tmp_top);
			tmp_top = stacks->a.head;
		}
		else
			tmp_top = tmp_top->next;
		if (chk < 2 && (tmp_bottom->numb == min_value || tmp_bottom->numb == max_value))
		{
			chk++;
			check_bottom_half(stacks, tmp_bottom);
			tmp_bottom = ft_lstlast(stacks->a.head);
		}
		else
			tmp_bottom = tmp_bottom->previous;
	}
}

static void	bring_back_numb_to_stack_a(t_stacks *stacks)
{
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
}

void	sort_list_of_five(t_stacks *stacks)
{
	push_min_and_max_value_to_stack_b(stacks);
	sort_list_of_three(stacks);
	bring_back_numb_to_stack_a(stacks);
}

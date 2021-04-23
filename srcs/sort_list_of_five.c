/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:27:05 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 23:06:55 by vscabell         ###   ########.fr       */
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

static void	atribute_variables(t_stacks *stacks, t_list **tmp, int *value)
{
	value[0] = get_min_value(&stacks->a);
	value[1] = get_max_value(&stacks->a);
	tmp[0] = ft_lstlast(stacks->a.head);
	tmp[1] = stacks->a.head;
}

static void	push_min_and_max_value_to_stack_b(t_stacks *stacks)
{
	t_list	*tmp[2];
	int		value[2];
	int		chk;

	atribute_variables(stacks, tmp, value);
	chk = 0;
	while (chk < 2 && tmp[1] && tmp[0])
	{
		if (tmp[1]->numb == value[0] || tmp[1]->numb == value[1])
		{
			chk++;
			check_top_half(stacks, tmp[1]);
			tmp[1] = stacks->a.head;
		}
		else
			tmp[1] = tmp[1]->next;
		if (chk < 2 && (tmp[0]->numb == value[0] || tmp[0]->numb == value[1]))
		{
			chk++;
			check_bottom_half(stacks, tmp[0]);
			tmp[0] = ft_lstlast(stacks->a.head);
		}
		else
			tmp[0] = tmp[0]->previous;
	}
}

void	sort_list_of_five(t_stacks *stacks)
{
	push_min_and_max_value_to_stack_b(stacks);
	sort_list_of_three(stacks);
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
}

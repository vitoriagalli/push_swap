/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:25:39 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 00:26:57 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//............................... //
//       SORT LIST OF TWO         //
//.............................. .//

void	sort_list_of_two(t_stacks *stacks)
{
	if (stacks-(stacks->a.head->numb > stacks->a.head->next->numb))
		call_operation("sa", stacks);
}

//............................... //
//       SORT LIST OF TREE        //
//.............................. .//

static void	atribute_args(t_list *lst, int *args)
{
	args[POS_0] = lst->numb;
	args[POS_1] = lst->next->numb;
	args[POS_2] = lst->next->next->numb;
}

static void	store_posit(t_range *posit, int *args)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = MAX_INT;
	max = MIN_INT;
	while (i < 3)
	{
		if (args[i] <= min)
		{
			min = args[i];
			posit->min = i;
		}
		if (args[i] >= max)
		{
			max = args[i];
			posit->max = i;
		}
		i++;
	}
}

static void	get_posit(t_list *lst, t_range *posit)
{
	int	args[3];

	atribute_args(lst, &args);
	store_posit(posit, &args);
	if (posit->min != POS_1 && posit->max != POS_1)
		posit->mid = POS_1;
	else if (posit->min != POS_2 && posit->max != POS_2)
		posit->mid = POS_2;
	else
		posit->mid = POS_0;
}

void	sort_list_of_three(t_stacks *stacks)
{
	t_range	posit;

	if (stacks->a.size < 3)
		return ;
	get_posit(stacks->a.head, &posit);
	if (posit.min == POS_0 && posit.mid == POS_2 && posit.max == POS_1)
	{
		call_operation("sa", stacks);
		call_operation("ra", stacks);
	}
	else if (posit.min == POS_1 && posit.mid == POS_0 && posit.max == POS_2)
		call_operation("sa", stacks);
	else if (posit.min == POS_1 && posit.mid == POS_2 && posit.max == POS_0)
		call_operation("ra", stacks);
	else if (posit.min == POS_2 && posit.mid == POS_1 && posit.max == POS_0)
	{
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (posit.min == POS_2 && posit.mid == POS_0 && posit.max == POS_1)
		call_operation("rra", stacks);
}

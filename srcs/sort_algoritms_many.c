/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms_many.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/20 23:55:45 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//............................... //
//         SORT COMPARE           //
//.............................. .//

void	push_elements_lesser_than_median(t_stacks *stacks, int median_a)
{
	int	median_b;

	median_b = get_median(stacks->b.head);
	if (ft_lstsize(stacks->a.head) < 2 || stacks->a.head->numb <= median_a)
	{
		call_operation("pb", stacks);
		if (stacks->b.head && stacks->b.head->numb < median_b)
		{
			if (stacks->a.head && stacks->a.head->numb > median_a)
				call_operation("rr", stacks);
			else
				call_operation("rb", stacks);
		}
	}
	else
	{
		if (stacks->b.head && stacks->b.head->numb < median_b)
			call_operation("rr", stacks);
		else
			call_operation("ra", stacks);
	}
}

void	compare_top_of_both_stacks(t_stacks *stacks)
{
	bool	sa;
	bool	sb;

	sa = false;
	sb = false;
	if (stacks->a.head && stacks->a.head->next && stacks->a.head->numb > stacks->a.head->next->numb)
		sa = true;
	if (stacks->b.head && stacks->b.head->next && stacks->b.head->numb < stacks->b.head->next->numb)
		sb = true;
	if (sa == true && sb == true)
		call_operation("ss", stacks);
	else if (sa == true)
		call_operation("sa", stacks);
	else if (sb == true)
		call_operation("sb", stacks);
}

void	loop_stack_a(t_stacks *stacks, int median_a)
{
	t_list	*tmp;
	size_t	init_size;
	size_t	i;

	tmp = stacks->a.head;
	init_size = stacks->a.size;
	i = 0;
	while (tmp && i < init_size)
	{
		push_elements_lesser_than_median(stacks, median_a);
		// compare_top_of_both_stacks(stacks);
		tmp = stacks->a.head;
		i++;
	}
}

void	empty_stack_a(t_stacks *stacks)
{
	int	median_a;

	while (stacks->a.size > 2)
	{
		median_a = get_median(stacks->a.head);
		loop_stack_a(stacks, median_a);
	}
	if ( stacks->a.head &&  stacks->a.head->next &&
		stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}





size_t	get_posit_max_value(t_stack *b, int bigger)
{
	t_list		*tmp;
	int			max;
	size_t		posit;
	size_t		i;

	i = 0;
	posit = 0;
	max = MIN_INT;
	tmp = b->head;
	while (tmp)
	{
		if (tmp->numb > max && tmp->numb != bigger)
		{
			max = tmp->numb;
			posit = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (posit);
}




void		empty_stack_b(t_stacks *stacks)
{
	int	max_value;
	int	posit_max_value;

	while (stacks->b.head)
	{
		max_value = get_max_value(&stacks->b);
		posit_max_value = get_posit_max_value(&stacks->b, MAX_INT);

		if (posit_max_value < (int)stacks->b.size / 2)
		{
			while (stacks->b.head->numb != max_value)
				call_operation("rb", stacks);
		}
		else
		{
			while (stacks->b.head->numb != max_value)
				call_operation("rrb", stacks);
		}
		call_operation("pa", stacks);

	}
}






void	sort_list_of_many(t_stacks *stacks)
{
	empty_stack_a(stacks);
	empty_stack_b(stacks);
}

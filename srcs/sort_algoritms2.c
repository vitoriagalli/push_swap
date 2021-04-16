/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 23:13:10 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
	(stacks->n_op)++;
}


//............................... //
//         SORT COMPARE           //
//.............................. .//


double	median(t_list *list)
{
	long long int	sum;
	int				fact;

	sum = 0;
	fact = ft_lstsize(list);
	if (fact == 0)
		return (0);
	while (list)
	{
		sum += list->numb;
		list = list->next;
	}
	return (sum / fact);
}

void	push_to_b_or_to_end_of_stack(t_stacks *stacks)
{
	t_list	*last;
	double	med;

	med = median(stacks->a.head);
	if (ft_lstsize(stacks->a.head) < 3|| med == 0 || stacks->a.head->numb < (int)med)
		call_operation("pb", stacks);
	else
	{
		last = ft_lstlast(stacks->b.head);
		if (stacks->b.head && stacks->b.head->next && stacks->b.head < last->numb)
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

void	ida(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->a.head;
	while (tmp)
	{
		push_to_b_or_to_end_of_stack(stacks);
		compare_top_of_both_stacks(stacks);
		tmp = stacks->a.head;

		// if (stacks->n_op  > 30)
		// 	break ;
	}


}

void	sort_compare(t_stacks *stacks)
{
	ida(stacks);
}

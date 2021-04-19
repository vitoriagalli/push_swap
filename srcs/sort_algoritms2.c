/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/20 00:09:26 by vscabell         ###   ########.fr       */
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


double	mean(t_list *list)
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
	// t_list	*last;
	int		med;

	med = get_median(stacks->a.head);
	// med = mean(stacks->a.head);
	if (ft_lstsize(stacks->a.head) < 3|| med == 0 || stacks->a.head->numb < med)
		call_operation("pb", stacks);
	else
	{
		// last = ft_lstlast(stacks->b.head);
		med = get_median(stacks->b.head);
		if (stacks->b.head && stacks->b.head->next && stacks->b.head->numb < med)
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
		// compare_top_of_both_stacks(stacks);
		tmp = stacks->a.head;

		if (stacks->n_op  > 100)
			break ;
	}

}

void	sort_compare(t_stacks *stacks)
{
	ida(stacks);
}




//#######################################################


void	get_hold(t_chunck *chunck, t_stack *stack)
{
	chunck->min = get_min_value(stack);
	chunck->max = get_max_value(stack);

	if (chunck->count < (chunck->lst_init_size * 1 / 5))
		chunck->hold = (chunck->min + chunck->max)/5;
	else if (chunck->count < (chunck->lst_init_size * 2 / 5))
		chunck->hold = (chunck->min + chunck->max)/4;
	else if (chunck->count < (chunck->lst_init_size * 3 / 5))
		chunck->hold = (chunck->min + chunck->max)/3;
	else if (chunck->count < (chunck->lst_init_size * 4 / 5))
		chunck->hold = (chunck->min + chunck->max)/2;
	else
		chunck->hold = (chunck->min + chunck->max)/1;
}

void	init_chunck(t_chunck *chunck)
{
	*chunck = (t_chunck){0};
}

void	ida2(t_stacks *stacks)
{
	t_chunck chunck;
	t_list	*tmp;

	init_chunck(&chunck);
	chunck.lst_init_size = ft_lstsize(stacks->a.head);

	tmp = stacks->a.head;
	while (tmp)
	{

		get_hold(&chunck, stacks);
		ft_printf("%i\n", chunck.hold);

		if (tmp->numb < chunck.hold)
		{
			call_operation("pb", stacks);
			chunck.count++;
		}

		// get_hold(&chunck, stacks);


		tmp = stacks->a.head;

		if (chunck.count > 100)
			break ;

		// if (stacks->n_op  > 100)
		// 	break ;
	}

}






void	sort_another_try(t_stacks *stacks)
{
	// ida2(stacks);

	get_median(stacks->a.head);
}

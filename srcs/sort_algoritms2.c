/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/20 02:05:28 by vscabell         ###   ########.fr       */
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

void	push_to_b_or_to_end_of_stack(t_stacks *stacks, int median_a)
{
	int	median_b;

	median_b = get_median(stacks->b.head);
	if (ft_lstsize(stacks->a.head) < 3 || stacks->a.head->numb < median_a)
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
		// median_b = get_median(stacks->b.head);
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


void	loop2(t_stacks *stacks, int median_a)
{
	size_t	init_size;
	t_list	*tmp;
	size_t	i;

	tmp = stacks->a.head;
	init_size = stacks->a.size;
	i = 0;
	while (tmp && i < init_size)
	{
		push_to_b_or_to_end_of_stack(stacks, median_a);

		// compare_top_of_both_stacks(stacks);
		tmp = stacks->a.head;
		i++;

		if (stacks->n_op > 100)
			break ;
	}
}



void	ida(t_stacks *stacks)
{
	int		median_a;

	while (stacks->a.head)
	{
		median_a = get_median(stacks->a.head);
		loop2(stacks, median_a);
	}


}

void	sort_compare(t_stacks *stacks)
{
	ida(stacks);
}

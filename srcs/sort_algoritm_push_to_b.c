/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:17:28 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 23:32:06 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_elements_lesser_than_median(t_stacks *stacks, int median_a)
{
	int	median_b;

	median_b = get_median(stacks->b.head);
	if (ft_lstsize(stacks->a.head) < 2 || stacks->a.head->numb <= median_a)
	{
		call_operation("pb", stacks);
		// if (stacks->b.head && stacks->b.head->numb < median_b)
		// {
		// 	if (stacks->a.head && stacks->a.head->numb > median_a)
		// 		call_operation("rr", stacks);
		// 	else
		// 		call_operation("rb", stacks);
		// }
	}
	else
	{
		if (stacks->b.head && stacks->b.head->numb < median_b)
			call_operation("rr", stacks);
		else
			call_operation("ra", stacks);
	}
}

static void	loop_stack_a(t_stacks *stacks, int median_a)
{
	t_list	*tmp;
	size_t	init_size;
	size_t	i;

	tmp = stacks->a.head;
	init_size = stacks->a.size;
	i = 0;
	// ft_printf("teste\n");
	while (tmp && i < init_size)
	{
		push_elements_lesser_than_median(stacks, median_a);
		tmp = stacks->a.head;
		i++;
	}
}

static void	push_to_b(t_stacks *stacks)
{
	int		median_a;
	size_t	size;

	size = stacks->a.size;
	while (stacks->a.size > 2)
	{
		if (stacks->a.size > 101)
			median_a = get_dynamic_median(stacks->a.head, size);
		else
			median_a = get_median(stacks->a.head);
		loop_stack_a(stacks, median_a);
	}
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

void	sort_list_of_many(t_stacks *stacks)
{
	push_to_b(stacks);
	push_to_a(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:01:43 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 23:48:43 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atribute_values(t_node *node, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = node->numb;
		node = node->next;
		i++;
	}
}

void	sort_list_two(t_stacks *stacks)
{
	int		numb[2];

	if (!stacks)
		return ;
	atribute_values(stacks->a.head, numb, 2);
	if (numb[0] > numb[1])
		call_operation("sa", stacks);
}

void	sort_list_three(t_stacks *stacks)
{
	int		numb[3];

	if (!stacks || stacks->a.size < 3)
		return ;
	atribute_values(stacks->a.head, numb, 3);
	if (numb[0] < numb[1] && numb[1] > numb[2] && numb[0] < numb[2])
	{
		call_operation("sa", stacks);
		call_operation("ra", stacks);
	}
	else if (numb[0] > numb[1] && numb[1] < numb[2] && numb[0] < numb[2])
		call_operation("sa", stacks);
	else if (numb[0] > numb[1] && numb[1] < numb[2] && numb[0] > numb[1])
		call_operation("ra", stacks);
	else if (numb[0] > numb[1] && numb[1] > numb[2] && numb[0] > numb[2])
	{
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (numb[0] < numb[1] && numb[1] > numb[2] && numb[0] > numb[2])
		call_operation("rra", stacks);
}

void	push_min_and_max_value_to_stack_b(t_stacks *stacks, int min, int max)
{
	t_node	*head;
	t_node	*last;
	size_t	size;
	size_t	i;

	i = 0;
	size = stacks->a.size;
	while (i < size)
	{
		head = stacks->a.head;
		last = ft_nodelast(stacks->a.head);
		if (head->numb == min || head->numb == max)
			call_operation("pb", stacks);
		else if (last->numb == min || last->numb == max)
		{
			call_operation("rra", stacks);
			call_operation("pb", stacks);
		}
		else
			call_operation("ra", stacks);
		i++;
	}
}

void	sort_list_five(t_stacks *stacks)
{
	size_t	n_plus;
	int		min;
	int		max;

	if (!stacks || stacks->a.size < 4)
		return ;
	n_plus = stacks->a.size - 3;
	min = get_min_value(stacks->a.head);
	if (n_plus > 1)
		max = get_max_value(stacks->a.head);
	else
		max = MAX_INT;
	push_min_and_max_value_to_stack_b(stacks, min, max);
	sort_list_three(stacks);
	while (n_plus)
	{
		call_operation("pa", stacks);
		if (stacks->a.head->numb == max)
			call_operation("ra", stacks);
		n_plus--;
	}
}

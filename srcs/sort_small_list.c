/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:01:43 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/23 01:44:23 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** atribute the node values in a array of ints
*/
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

/*
** sort two elements is stack A
*/
void	sort_list_two(t_stacks *stacks)
{
	int		numb[2];

	if (!stacks)
		return ;
	atribute_values(stacks->a.head, numb, 2);
	if (numb[0] > numb[1])
		call_operation("sa", stacks);
}

/*
** sort three elements is stack A (without the help of stack B)
*/
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

/*
** iterate the stack A and check for min and max values to push to stack B
** check the head of the stack and the last node as well
*/
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

/*
** push the min and max value in stack A to the stack B
** (if the list size = 4, push only the min)
** sort the stack A with the remaining nodes
** push back the nodes from B
*/
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

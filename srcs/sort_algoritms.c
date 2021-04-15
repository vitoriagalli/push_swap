/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:12:45 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/15 02:39:04 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
}

//............................... //
//        INSERTION SORT          //
//.............................. .//

size_t	get_posit_min_value(t_stack *a)
{
	t_list		*tmp;
	int			min;
	size_t		posit;
	size_t		i;

	i = 0;
	posit = 0;
	min = 2147483647;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->numb < min)
		{
			min = tmp->numb;
			posit = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (posit);
}

void	push_min_value_to_top_of_stack(t_stacks *stacks, size_t posit)
{
	size_t	i;

	i = 0;
	while (i < posit)
	{
		call_operation("ra", stacks);
		i++;
	}
}

void	insertion_sort(t_stacks *stacks)
{
	size_t	posit;
	size_t	size;

	size = ft_lstsize(stacks->a.head);
	while (size > 0)
	{
		posit = get_posit_min_value(&stacks->a);
		push_min_value_to_top_of_stack(stacks, posit);
		call_operation("pb", stacks);
		size--;
	}
	size = ft_lstsize(stacks->b.head);
	while (size > 0)
	{
		call_operation("pa", stacks);
		size--;
	}
}

//............................... //
//       SORT LIST OF TREE        //
//.............................. .//

void	get_posit(int *args, int *posit)
{
	int	i;
	int	m[3];

	i = 0;
	ft_memcpy(m, args, 3 * sizeof(int));
	while (i < 3)
	{
		if (args[i] <= m[0])
		{
			m[0] = args[i];
			posit[0] = i;
		}
		if (args[i] >= m[2])
		{
			m[2] = args[i];
			posit[2] = i;
		}
		i++;
	}
	if (posit[0] != 1 && posit[2] != 1)
		posit[1] = 1;
	else if (posit[0] != 2 && posit[2] != 2)
		posit[1] = 2;
	else
		posit[1] = 0;
}

void	sort_list_of_tree(t_stacks *stacks)
{
	int	posit[3];
	int	args[3];

	if (stacks->a.size < 3)
		return ;
	args[0] = stacks->a.head->numb;
	args[1] = stacks->a.head->next->numb;
	args[2] = stacks->a.head->next->next->numb;;

	get_posit(args, posit);
	if (posit[0] == 0 && posit[1] == 2 && posit[2] == 1)
	{
		call_operation("sa", stacks);
		call_operation("ra", stacks);
	}
	else if (posit[0] == 1 && posit[1] == 0 && posit[2] == 2)
		call_operation("sa", stacks);
	else if (posit[0] == 1 && posit[1] == 2 && posit[2] == 0)
		call_operation("ra", stacks);
	else if (posit[0] == 2 && posit[1] == 1 && posit[2] == 0)
	{
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (posit[0] == 2 && posit[1] == 0 && posit[2] == 1)
		call_operation("rra", stacks);
}

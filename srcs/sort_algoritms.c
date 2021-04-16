/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:12:45 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 21:55:05 by vscabell         ###   ########.fr       */
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

void	atribute_args(t_list *lst, int *args)
{
	args[POS_0] = lst->numb;
	args[POS_1] = lst->next->numb;
	args[POS_2] = lst->next->next->numb;
}

void	get_posit(t_list *lst, t_three *posit)
{
	int	args[3];
	int	min;
	int	max;
	int	i;

	atribute_args(lst, &args);
	i = 0;
	min = 2147483647;
	max = -2147483648;
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
	if (posit->min != POS_1 && posit->max != POS_1)
		posit->mid = POS_1;
	else if (posit->min != POS_2 && posit->max != POS_2)
		posit->mid = POS_2;
	else
		posit->mid = POS_0;
}

void	sort_list_of_tree_a(t_stacks *stacks)
{
	t_three	posit;

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

void	sort_list_of_tree(t_stacks *stacks)
{
	sort_list_of_tree_a(stacks);
}

//............................... //
//       SORT LIST OF FIVE        //
//.............................. .//

int		get_max_value(t_stack *a)
{
	t_list		*tmp;
	int			max;

	max = -2147483648;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->numb > max)
			max = tmp->numb;
		tmp = tmp->next;
	}
	return (max);
}

int		get_min_value(t_stack *a)
{
	t_list		*tmp;
	int			min;

	min = 2147483647;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->numb < min)
			min = tmp->numb;
		tmp = tmp->next;
	}
	return (min);
}

void	check_top_half(t_stacks *stacks, t_list *tmp)
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

void	check_bottom_half(t_stacks *stacks, t_list *tmp)
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

void	loop(t_stacks *stacks)
{
	t_list	*tmp_top;
	t_list	*tmp_bottom;
	int		min_value;
	int		max_value;

	min_value = get_min_value(&stacks->a);
	max_value = get_max_value(&stacks->a);


	tmp_bottom = ft_lstlast(stacks->a.head);
	tmp_top = stacks->a.head;
	while (tmp_top && tmp_bottom)
	{
		if (tmp_top->numb == min_value)// || tmp_bottom->numb == max_value)
		{
			check_top_half(stacks, tmp_top);
			min_value = -2147483648;
		}
		else if (tmp_bottom->numb == min_value)// || tmp_bottom->numb == max_value)
		{
			check_bottom_half(stacks, tmp_bottom);
			min_value = -2147483648;
		}
		if (tmp_top->numb == max_value)
		{
			check_top_half(stacks, tmp_top);
			max_value = 2147483647;
		}
		else if (tmp_bottom->numb == max_value)
		{
			check_bottom_half(stacks, tmp_bottom);
			max_value = 2147483647;
		}
		tmp_top = tmp_top->next;
		tmp_bottom = tmp_bottom->previous;
	}
}

void	bring_back_to_a(t_stacks *stacks)
{
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
	call_operation("pa", stacks);
	if (stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("ra", stacks);
}


void	sort_list_of_five(t_stacks *stacks)
{
	// if (stacks->a.size < 5)
	// 	return ;

	loop(stacks);
	sort_list_of_tree_a(stacks);
	bring_back_to_a(stacks);

}


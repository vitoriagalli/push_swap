/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_push_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/16 03:53:29 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ascending(int a, int b)
{
	return (a > b);
}

static bool	descending(int a, int b)
{
	return (a < b);
}

static int	sort_nodes_by_posit_and_get_op(char **op, t_node **max, int size)
{
	int	longest_posit;

	if ((*max)->top_half)
	{
		*op = "rb";
		longest_posit = sort_nodes_by_posit(max, ascending);
	}
	else
	{
		*op = "rrb";
		longest_posit = sort_nodes_by_posit(max, descending);
		longest_posit = size - longest_posit;
	}
	return (longest_posit);
}

static size_t	atribute_max_values(t_node **max, t_stack *stack)
{
	t_node		*new;
	bool		max_top_half;
	int			val_max;
	int			i;

	i = 0;
	val_max = MAX_INT;
	while (i < 3)
	{
		new = ft_nodenew(stack, get_max_value_but_n(stack, val_max));
		if (!new)
			return (-1);
		if (i == 0)
			max_top_half = new->top_half;
		else if (new->top_half != max_top_half || new->value == MIN_INT)
		{
			free(new);
			return (i);
		}
		ft_nodeadd_back(max, new);
		val_max = new->value;
		i++;
	}
	return (i);
}


static size_t	atribute_min_values(t_node **min, t_stack *stack)
{
	t_node		*new;
	bool		min_top_half;
	int			val_min;
	int			i;

	i = 0;
	val_min = MIN_INT;
	while (i < 3)
	{
		new = ft_nodenew(stack, get_min_value_but_n(stack, val_min));
		if (!new)
			return (-1);
		if (i == 0)
			min_top_half = new->top_half;
		else if (new->top_half != min_top_half || new->value == MAX_INT)
		{
			free(new);
			return (i);
		}
		ft_nodeadd_back(min, new);
		val_min = new->value;
		i++;
	}
	return (i);
}


void	push_value(t_stacks *stacks, t_node **max_list, int values_to_push_size,
	char *op)
{
	if (values_to_push_size == 1)
		rotate_and_push_value(stacks, op, (*max_list)->value);
	else if (values_to_push_size == 2)
		rotate_and_push_two_values(stacks, op, *max_list);
	else
		rotate_and_push_three_values(stacks, op, *max_list);
}


void	push_to_a(t_stacks *stacks)
{
	t_node	*max_list;
	t_node	*min_list;
	int		max_values_to_push_size;
	int		min_values_to_push_size;

	char	*op_max = NULL;
	char	*op_min = NULL;

	while (stacks->b.head)
	{
		max_list = NULL;
		max_values_to_push_size = atribute_max_values(&max_list, &stacks->b);
		if (max_values_to_push_size == -1)
			exit_push_swap(stacks, &max_list);
		int longest_posit_max = sort_nodes_by_posit_and_get_op(&op_max, &max_list, stacks->b.size);


		min_list = NULL;
		min_values_to_push_size = atribute_min_values(&min_list, &stacks->b);
		if (min_values_to_push_size == -1)
			exit_push_swap(stacks, &min_list);
		int longest_posit_min = sort_nodes_by_posit_and_get_op(&op_min, &min_list, stacks->b.size);




		if (longest_posit_min < longest_posit_max)
		{
			push_value(stacks, &min_list, min_values_to_push_size, op_min);
			while(min_values_to_push_size)
			{
				// ft_printf("A\n");
				call_operation("ra", stacks);	// é chamado em media de 60 a 300 vezes
				min_values_to_push_size--;
			}
		}
		else
		{
			push_value(stacks, &max_list, max_values_to_push_size, op_max);
		}

		ft_nodeclear(&max_list);
		ft_nodeclear(&min_list);
	}

	while (ft_lstlast(stacks->a.head)->numb < stacks->a.head->numb)
	{
		call_operation("rra", stacks);
		// call_operation("ra", stacks);
	}


}

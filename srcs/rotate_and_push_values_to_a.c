/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_values_to_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:45:36 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 20:25:09 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_push_value(t_stacks *stacks, char *op, int value)
{
	while (stacks->b.head && stacks->b.head->numb != value)
		call_operation(op, stacks);
	call_operation("pa", stacks);
}

void	rotate_and_push_two_values(t_stacks *stacks, char *op, t_node *max)
{
	rotate_and_push_value(stacks, op, max->value);
	rotate_and_push_value(stacks, op, max->next->value);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

void	rotate_and_push_three_values(t_stacks *stacks, char *op, t_node *max)
{
	rotate_and_push_value(stacks, op, max->value);
	rotate_and_push_value(stacks, op, max->next->value);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
			call_operation("sa", stacks);
	if (max->next->next->value > max->value
		&& max->next->next->value > max->next->value)
	{
		while (stacks->b.head->numb != max->next->next->value )
			call_operation(op, stacks);
		call_operation("ra", stacks);
		call_operation("pa", stacks);
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else
	{
		rotate_and_push_value(stacks, op, max->next->next->value );
		if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
			call_operation("sa", stacks);
	}
}








// void	atribute_values(int *tab, t_node *max, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	while (max && i < size)
// 	{
// 		tab[i] = max->value;
// 		max = max->next;
// 		i++;
// 	}
// }


// void	rotate_and_push_three_values(t_stacks *stacks, char *op, t_node *max)
// {
// 	// int		value[3];
// 	// int		index_max;
// 	// bool	max_ok;


// 	// atribute_values(value, max, 3);
// 	// ft_sort_int_tab(value, 3); // dessa forma o maior esta no fim da tabela
// 	// index_max = 2;


// 	// rotate_and_push_value(stacks, op, max->value);
// 	// if (stacks->a.head->numb != value[index_max])
// 	// 	call_operation ("ra", stacks);
// 	// else
// 	// 	index_max--;


// 	// rotate_and_push_value(stacks, op, max->next->value);
// 	// if (stacks->a.head->numb != value[index_max])
// 	// 	call_operation ("ra", stacks);
// 	// else
// 	// 	index_max--;


// 	// while (stacks->b.head->numb != max->next->next->value)
// 	// 	call_operation(op, stacks);
// 	// if (stacks->a.head->numb == value[index_max])
// 	// {
// 	// 	call_operation ("pa", stacks);
// 	// 	call_operation ("rra", stacks);
// 	// 	call_operation ("rra", stacks);
// 	// 	if (stacks->a.head && stacks->a.head->next
// 	// 	&& stacks->a.head->numb > stacks->a.head->next->numb)
// 	// 		call_operation("sa", stacks);
// 	// }
// 	// else
// 	// {
// 	// 	call_operation ("rra", stacks);
// 	// 	call_operation ("pa", stacks);
// 	// }


// }






// void	rotate_and_push_four_values(t_stacks *stacks, char *op, t_node *max)
// {
// 	int		value[4];
// 	bool	max_ok;


// 	atribute_values(value, max, 4);
// 	ft_sort_int_tab(value, 4); // dessa forma o maior esta no fim da tabela

// 	rotate_and_push_value(stacks, op, max->value);
// 	if (stacks->a.head->numb != value[3])
// 		call_operation ("ra", stacks);
// 	else
// 		max_ok = true;

// 	rotate_and_push_value(stacks, op, max->next->value);
// 	if (stacks->a.head->numb != value[3])
// 		call_operation ("ra", stacks);
// 	else
// 		max_ok = true;

// 	rotate_and_push_value(stacks, op, max->next->next->value);
// 	if (stacks->a.head->numb != value[3])
// 		call_operation ("ra", stacks);
// 	else
// 		max_ok = true;

// 	if (stacks->b.head)
// 	{
// 		while (stacks->b.head->numb != max->next->next->next->value)
// 			call_operation(op, stacks);
// 	}


// 	if (max_ok == true)
// 	{
// 		if (stacks->b.head->numb > ft_lstlast(stacks->b.head)->numb
// 			&& stacks->b.head->numb > ft_lstlast(stacks->b.head)->previous->numb)
// 			call_operation ("pa", stacks);
// 		call_operation("rra", stacks);
// 		call_operation("rra", stacks);
// 		if (stacks->a.head && stacks->a.head->next
// 			&& stacks->a.head->numb > stacks->a.head->next->numb)
// 			call_operation("sa", stacks);
// 	}






// 	// if (max_ok == true)
// 	// {
// 	// 	call_operation ("rra", stacks);
// 	// 	call_operation ("rra", stacks);

// 	// 	if (stacks->a.head && stacks->a.head->next
// 	// 		&& stacks->a.head->numb > stacks->a.head->next->numb)
// 	// 			call_operation("sa", stacks);
// 	// 	if (max->next->next->value > max->value
// 	// 		&& max->next->next->value > max->next->value)
// 	// 	{
// 	// 		while (stacks->b.head->numb != max->next->next->value )
// 	// 			call_operation(op, stacks);
// 	// 		call_operation("ra", stacks);
// 	// 		call_operation("pa", stacks);
// 	// 		call_operation("sa", stacks);
// 	// 		call_operation("rra", stacks);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		rotate_and_push_value(stacks, op, max->next->next->value );
// 	// 		if (stacks->a.head && stacks->a.head->next
// 	// 		&& stacks->a.head->numb > stacks->a.head->next->numb)
// 	// 			call_operation("sa", stacks);
// 	// 	}

// 	// }
// 	// else
// 	// {
// 	// 	call_operation("sa", stacks);
// 	// }



// }

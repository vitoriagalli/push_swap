/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms_push_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/21 18:09:20 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_posit_value(t_stack *b, int numb)
{
	t_list		*tmp;;
	size_t		i;

	i = 0;
	tmp = b->head;
	while (tmp)
	{
		if (tmp->numb == numb)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (b->size + 1);
}

void	atribute_max_values(t_node *max, t_node *second_max, t_node *third_max,
	t_stack *stack)
{
	max->value = get_max_value_but_n(stack, MAX_INT); // verificar caso haja max int
	max->posit = get_posit_value(stack, max->value);
	second_max->value = get_max_value_but_n(stack, max->value);
	second_max->posit = get_posit_value(stack, second_max->value);
	third_max->value = get_max_value_but_n(stack, second_max->value);
	third_max->posit = get_posit_value(stack, third_max->value);
}

void	rotate_and_push_value(t_stacks *stacks, char *cmd, int value)
{
	while (stacks->b.head->numb != value)
		call_operation(cmd, stacks);
	call_operation("pa", stacks);
}

void	rotate_and_push_two_values(t_stacks *stacks, char *cmd, t_node *max,
	t_node *second_max)
{
	int		first_to_push;
	int		second_to_push;

	if ((max->top_half && max->posit < second_max->posit)
		|| (!max->top_half && max->posit > second_max->posit))
	{
		first_to_push = max->value;
		second_to_push = second_max->value;
	}
	else
	{
		first_to_push = second_max->value;
		second_to_push = max->value;
	}

	rotate_and_push_value(stacks, cmd, first_to_push);
	rotate_and_push_value(stacks, cmd, second_to_push);

	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}



void	rotate_and_push_three_values(t_stacks *stacks, char *cmd, t_node *max,
	t_node *second_max, t_node *third_max)
{
	int		first_to_push;
	int		second_to_push;
	int		third_to_push;

	t_node	*pmin, *pmed, *pmax;

	if (max->posit < second_max->posit && max->posit < third_max->posit)
		pmin = max;
	else if (second_max->posit < max->posit && second_max->posit < third_max->posit)
		pmin = second_max;
	else
		pmin = third_max;


	if (max->posit > second_max->posit && max->posit > third_max->posit)
		pmax = max;
	else if (second_max->posit > max->posit && second_max->posit > third_max->posit)
		pmax = second_max;
	else
		pmax = third_max;


	if (!(pmin == max || pmax == max))
		pmed = max;
	else if (!(pmin == second_max || pmax == second_max))
		pmed = second_max;
	else
		pmed = third_max;


	if (max->top_half)
	{
		first_to_push = pmin->value;
		second_to_push = pmed->value;
		third_to_push = pmax->value;
	}
	else
	{
		first_to_push = pmax->value;
		second_to_push = pmed->value;
		third_to_push = pmin->value;
	}

	rotate_and_push_value(stacks, cmd, first_to_push);
	rotate_and_push_value(stacks, cmd, second_to_push);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);

	rotate_and_push_value(stacks, cmd, third_to_push);

	if (stacks->a.head && stacks->a.head->next && stacks->a.head->next->next
		&& stacks->a.head->numb > stacks->a.head->next->next->numb)
	{
		call_operation("pb", stacks);
		call_operation("ra", stacks);
		call_operation("pa", stacks);
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}


void	push_to_a(t_stacks *stacks)
{
	t_node	max;
	t_node	second_max;
	t_node	third_max;
	char	*cmd;

	while (stacks->b.head)
	{
		atribute_max_values(&max, &second_max, &third_max, &stacks->b);
		max.top_half = max.posit < (int)(stacks->b.size / 2);
		second_max.top_half = second_max.posit < (int)(stacks->b.size / 2);
		third_max.top_half = third_max.posit < (int)(stacks->b.size / 2);

		if (max.top_half)
			cmd = "rb";
		else
			cmd = "rrb";

		if (!(second_max.posit < stacks->b.size)
			|| (max.top_half ^ second_max.top_half))
			rotate_and_push_value(stacks, cmd, max.value);
		// else
		// 	rotate_and_push_two_values(stacks, cmd, &max, &second_max);


		else if (!(third_max.posit < stacks->b.size)
			|| (max.top_half ^ third_max.top_half))
			rotate_and_push_two_values(stacks, cmd, &max, &second_max);
		else
			rotate_and_push_three_values(stacks, cmd, &max, &second_max,
			&third_max);
	}
}


void	sort_list_of_many(t_stacks *stacks)
{
	push_to_b(stacks);
	push_to_a(stacks);
}

// algo is not working:
// 100 num - min int
// 500 num - min and max int

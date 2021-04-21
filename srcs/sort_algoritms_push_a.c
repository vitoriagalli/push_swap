/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms_push_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/21 18:29:59 by vscabell         ###   ########.fr       */
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

void	atribute_max_values(t_nodes *n, t_stack *stack)
{
	n->max.value = get_max_value_but_n(stack, MAX_INT); // verificar caso haja max int
	n->max.posit = get_posit_value(stack, n->max.value);
	n->second_max.value = get_max_value_but_n(stack, n->max.value);
	n->second_max.posit = get_posit_value(stack, n->second_max.value);
	n->third_max.value = get_max_value_but_n(stack, n->second_max.value);
	n->third_max.posit = get_posit_value(stack, n->third_max.value);
}

void	rotate_and_push_value(t_stacks *stacks, char *cmd, int value)
{
	while (stacks->b.head->numb != value)
		call_operation(cmd, stacks);
	call_operation("pa", stacks);
}

void	rotate_and_push_two_values(t_stacks *stacks, char *cmd, t_nodes *n)
{
	int		first_to_push;
	int		second_to_push;

	if ((n->max.top_half && n->max.posit < n->second_max.posit)
		|| (!n->max.top_half && n->max.posit > n->second_max.posit))
	{
		first_to_push = n->max.value;
		second_to_push = n->second_max.value;
	}
	else
	{
		first_to_push = n->second_max.value;
		second_to_push = n->max.value;
	}
	rotate_and_push_value(stacks, cmd, first_to_push);
	rotate_and_push_value(stacks, cmd, second_to_push);
	if (stacks->a.head && stacks->a.head->next
		&& stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

void	rotate_and_push_three_values(t_stacks *stacks, char *cmd, t_nodes *n)
{
	int		first_to_push;
	int		second_to_push;
	int		third_to_push;

	t_node	*pmin, *pmed, *pmax;

	if (n->max.posit < n->second_max.posit && n->max.posit < n->third_max.posit)
		pmin = &n->max;
	else if (n->second_max.posit < n->max.posit && n->second_max.posit < n->third_max.posit)
		pmin = &n->second_max;
	else
		pmin = &n->third_max;


	if (n->max.posit > n->second_max.posit && n->max.posit > n->third_max.posit)
		pmax = &n->max;
	else if (n->second_max.posit > n->max.posit && n->second_max.posit > n->third_max.posit)
		pmax = &n->second_max;
	else
		pmax = &n->third_max;


	if (!(pmin == &n->max || pmax == &n->max))
		pmed = &n->max;
	else if (!(pmin == &n->second_max || pmax == &n->second_max))
		pmed = &n->second_max;
	else
		pmed = &n->third_max;


	if (n->max.top_half)
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
	t_nodes	n;
	char	*cmd;

	while (stacks->b.head)
	{
		atribute_max_values(&n, &stacks->b);
		n.max.top_half = n.max.posit < (int)(stacks->b.size / 2);
		n.second_max.top_half = n.second_max.posit < (int)(stacks->b.size / 2);
		n.third_max.top_half = n.third_max.posit < (int)(stacks->b.size / 2);
		if (n.max.top_half)
			cmd = "rb";
		else
			cmd = "rrb";
		if (!(n.second_max.posit < stacks->b.size)
			|| (n.max.top_half ^ n.second_max.top_half))
			rotate_and_push_value(stacks, cmd, n.max.value);
		else if (!(n.third_max.posit < stacks->b.size)
			|| (n.max.top_half ^ n.third_max.top_half))
			rotate_and_push_two_values(stacks, cmd, &n);
		else
			rotate_and_push_three_values(stacks, cmd, &n);
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

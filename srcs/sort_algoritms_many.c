/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms_many.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:22 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/21 03:57:16 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//............................... //
//         SORT COMPARE           //
//.............................. .//

void	push_elements_lesser_than_median(t_stacks *stacks, int median_a)
{
	int	median_b;

	median_b = get_median(stacks->b.head);
	if (ft_lstsize(stacks->a.head) < 2 || stacks->a.head->numb <= median_a)
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

void	loop_stack_a(t_stacks *stacks, int median_a)
{
	t_list	*tmp;
	size_t	init_size;
	size_t	i;

	tmp = stacks->a.head;
	init_size = stacks->a.size;
	i = 0;
	while (tmp && i < init_size)
	{
		push_elements_lesser_than_median(stacks, median_a);
		// compare_top_of_both_stacks(stacks);
		tmp = stacks->a.head;
		i++;
	}
}

void	empty_stack_a(t_stacks *stacks)
{
	int	median_a;

	while (stacks->a.size > 2)
	{
		median_a = get_median(stacks->a.head);
		loop_stack_a(stacks, median_a);
	}
	if ( stacks->a.head &&  stacks->a.head->next &&
		stacks->a.head->numb > stacks->a.head->next->numb)
		call_operation("sa", stacks);
}

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

void		empty_stack_b(t_stacks *stacks)
{
	int		max_value;
	int		second_max_value;
	int		posit_max_value;
	int		posit_second_max_value;
	bool	max_top_half;
	bool	sec_max_top_half;
	bool	closer_max;
	bool	second;
	char	*cmd;

	int		first_n;
	int		second_n;

	while (stacks->b.head)
	{
		max_top_half = false;
		sec_max_top_half = false;
		closer_max = false;
		second = false;


		max_value = get_max_value_but_n(&stacks->b, MAX_INT); // verificar caso haja max int
		posit_max_value = get_posit_value(&stacks->b, max_value);

		second_max_value = get_max_value_but_n(&stacks->b, max_value);
		posit_second_max_value = get_posit_value(&stacks->b, second_max_value);
		if (posit_second_max_value < stacks->b.size)
			second = true;



		if (posit_max_value < (int)(stacks->b.size / 2))
		{
			max_top_half = true;
			cmd = "rb";
		}
		else
			cmd = "rrb";


		if (posit_second_max_value < (int)(stacks->b.size / 2))
			sec_max_top_half = true;



		if (second && !(max_top_half ^ sec_max_top_half))
		{
			if (max_top_half)
			{
				if (posit_max_value < posit_second_max_value)
					closer_max = true;
			}
			else
			{
				if (posit_max_value > posit_second_max_value)
					closer_max = true;
			}




			if (closer_max)
			{
				first_n = max_value;
				second_n = second_max_value;
			}
			else
			{
				first_n = second_max_value;
				second_n = max_value;
			}



			while (stacks->b.head->numb != first_n)
				call_operation(cmd, stacks);
			call_operation("pa", stacks);


			while (stacks->b.head->numb != second_n)
				call_operation(cmd, stacks);
			call_operation("pa", stacks);


			if (stacks->a.head && stacks->a.head->next
				&& stacks->a.head->numb > stacks->a.head->next->numb)
				call_operation("sa", stacks);

		}
		else
		{
			while (stacks->b.head->numb != max_value)
				call_operation(cmd, stacks);
			call_operation("pa", stacks);
		}
	}
}

void	sort_list_of_many(t_stacks *stacks)
{
	empty_stack_a(stacks);
	empty_stack_b(stacks);


	// if (!(false ^ false))
	// 	ft_printf("teste\n");
}

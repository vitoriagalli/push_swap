/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:53:00 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 16:19:55 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

void	operations(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa"))
		swap(&stacks->a);
	else if (!ft_strcmp(op, "sb"))
		swap(&stacks->b);
	else if (!ft_strcmp(op, "sss"))
	{
		swap(&stacks->a);
		swap(&stacks->b);
	}
	else if (!ft_strcmp(op, "pa"))
		push(&stacks->a, &stacks->b);
	else if (!ft_strcmp(op, "pb"))
		push(&stacks->b, &stacks->a);
	else if (!ft_strcmp(op, "ra"))
		rotate(&stacks->a);
	else if (!ft_strcmp(op, "rb"))
		rotate(&stacks->b);
	else if (!ft_strcmp(op, "rr"))
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
	}
	else if (!ft_strcmp(op, "rra"))
		reverse_rotate(&stacks->a);
	else if (!ft_strcmp(op, "rrb"))
		reverse_rotate(&stacks->b);
	else if (!ft_strcmp(op, "rrr"))
	{
		reverse_rotate(&stacks->a);
		reverse_rotate(&stacks->b);
	}
}

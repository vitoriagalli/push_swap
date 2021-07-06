/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:53:00 by vscabell          #+#    #+#             */
/*   Updated: 2021/07/06 14:47:09 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

bool	operations(char *op, t_stacks *stacks)
{
	bool	valid;

	valid = false;
	if (!ft_strcmp(op, "pa"))
		valid = push(&stacks->a, &stacks->b);
	if (!ft_strcmp(op, "pb"))
		valid = push(&stacks->b, &stacks->a);
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		valid = swap(&stacks->a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		valid = swap(&stacks->b);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		valid = rotate(&stacks->a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		valid = rotate(&stacks->b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		valid = reverse_rotate(&stacks->a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		valid = reverse_rotate(&stacks->b);
	return (valid);
}

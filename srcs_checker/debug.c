/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:39:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 16:29:07 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	ft_printf("size:\t%i\n", stack.size);
	ft_printf("stack:");
	while (i < stack.size)
	{
		ft_printf("\t%i\n", stack.head->content);
		stack.head = stack.head->next;
		i++;
	}
	ft_printf("\n");
}


void	print_both_stacks(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	ft_printf("\tA\tB\n");
	ft_printf("\t--\t--\n");
	ft_printf("size:\t%i\t%i\n", a.size, b.size);
	ft_printf("stack:");
	while (i < a.size || i < b.size)
	{
		if (i < a.size)
		{
			ft_printf("\t%i", a.head->content);
			a.head = a.head->next;
		}
		if (i < b.size)
		{
			ft_printf("\t%i", b.head->content);
			b.head = b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	print_stacks(t_stacks stacks)
{
	int	i;

	i = 0;
	ft_printf("\tA\tB\n");
	ft_printf("\t--\t--\n");
	ft_printf("size:\t%i\t%i\n", stacks.a.size, stacks.b.size);
	ft_printf("stack:");
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			ft_printf("\t%i", stacks.a.head->content);
			stacks.a.head = stacks.a.head->next;
		}
		if (i < stacks.b.size)
		{
			ft_printf("\t%i", stacks.b.head->content);
			stacks.b.head = stacks.b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

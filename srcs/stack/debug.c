/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:39:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/12 02:48:41 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	print_stacks(t_stacks stacks)
{
	size_t	i;

	i = 0;
	ft_printf("\nsize:\t%i\t%i\nstack:", stacks.a.size, stacks.b.size);
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			ft_printf("\t%i", stacks.a.head->content);
			if (stacks.a.head->next)
				stacks.a.head = stacks.a.head->next;
		}
		else
			ft_printf("\t");
		if (i < stacks.b.size)
		{
			ft_printf("\t%i", stacks.b.head->content);
			if (stacks.b.head->next)
				stacks.b.head = stacks.b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\t_\t_\n\ta\tb\ncmd: ");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:39:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 21:51:31 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stacks(t_stacks stacks)
{
	size_t	i;

	i = 0;
	ft_printf("\tA\tB\n");
	ft_printf("\t--\t--\n");
	ft_printf("size:\t%i\t%i\n", stacks.a.size, stacks.b.size);
	ft_printf("stack:");
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size && stacks.a.head->next)
		{
			ft_printf("\t%i", stacks.a.head->content);
			stacks.a.head = stacks.a.head->next;
		}
		if (i < stacks.b.size && stacks.b.head->next)
		{
			ft_printf("\t%i", stacks.b.head->content);
			stacks.b.head = stacks.b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

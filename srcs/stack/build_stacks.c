/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:17:31 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 03:58:22 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	build_stacks(char **argv, t_stacks *stacks)
{
	t_list	*new_node;
	long	numb;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while (argv[stacks->a.size])
	{
		numb = ft_atoi(argv[stacks->a.size]);
		new_node = ft_lstnew((void *)numb);
		if (!new_node)
			exit_program(stacks);
		ft_lstadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}

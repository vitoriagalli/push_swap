/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:17:31 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 03:42:29 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	exit_program(t_stacks *stacks)
{
	clear_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	validate_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_array_clear(argv);
		exit(EXIT_SUCCESS);
	}
	if (!validate_params(argv))
	{
		ft_array_clear(argv);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:17:31 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/11 19:18:43 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_program(t_stacks *stacks)
{
	clear_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	validate_args(int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (!validate_params(argc, argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	build_stacks(int argc, char **argv, t_stacks *stacks)
{
	t_list	*new_node;
	long	numb;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while ((int)stacks->a.size < (argc - 1))
	{
		numb = ft_atoi(argv[stacks->a.size + 1]);
		new_node = ft_lstnew((void *)numb);
		if (!new_node)
			exit_program(stacks);
		ft_lstadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}

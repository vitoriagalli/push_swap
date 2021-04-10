/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 16:28:29 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_program(void)
{
	exit(0);
}

void	validate_args(int argc, char **argv)
{
	if (!validate_params(argc, argv))
	{
		ft_printf("Error\n");
		exit_program();
	}
}

void	build_stack_a(int argc, char **argv, t_stack *stack)
{
	t_list	*new_node;

	*stack = (t_stack){0};
	while (stack->size < argc - 1)
	{
		new_node = ft_lstnew((int)ft_atoi(argv[stack->size + 1]));
		if (!new_node)
			exit_program();
		ft_lstadd_back(&stack->head, new_node);
		(stack->size)++;
	}
}

void	build_stacks(int argc, char **argv, t_stacks *stacks)
{
	t_list	*new_node;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	build_stack_a(argc, argv, &stacks->a);
}


int	main(int argc, char **argv)
{
	t_stacks stacks;

	validate_args(argc, argv);
	build_stacks(argc, argv, &stacks);
	print_stacks(stacks);

	operations("sa", &stacks);
	print_stacks(stacks);

	operations("pb", &stacks);
	operations("pb", &stacks);
	operations("pb", &stacks);
	print_stacks(stacks);

	clear_stacks(stacks);
	return (0);
}

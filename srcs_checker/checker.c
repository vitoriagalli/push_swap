/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 03:39:40 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stack.h"

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

void	build_stack_b(t_stack *stack)
{
	*stack = (t_stack){0};
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	validate_args(argc, argv);
	build_stack_a(argc, argv, &stack_a);
	build_stack_b(&stack_b);
	print_both_stacks(stack_a, stack_b);

	swap(&stack_a);
	print_both_stacks(stack_a, stack_b);

	push(&stack_b, &stack_a);
	print_both_stacks(stack_a, stack_b);

	return (0);
}

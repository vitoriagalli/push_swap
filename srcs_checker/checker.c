/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 02:37:51 by vscabell         ###   ########.fr       */
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

void	build_stack(int argc, char **argv, t_stack *stack)
{
	int	i;

	stack->size = argc - 1;
	stack->arr = malloc(stack->size * sizeof(int));
	if (!stack->arr)
		exit_program();
	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	validate_args(argc, argv);
	build_stack(argc, argv, &stack);
	print_stack(stack);
	return (0);
}

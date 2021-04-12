/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:27 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/12 03:41:59 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list		*head;
	size_t		size;
}				t_stack;

void	swap(t_stack *stack);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

typedef struct s_stacks
{
	t_stack		a;
	t_stack		b;
}				t_stacks;

bool	validate_params(int argc, char **argv);
void	validate_args(int argc, char **argv);
void	build_stacks(int argc, char **argv, t_stacks *stacks);
void	operations(char *op, t_stacks *stacks);
void	check_if_is_sorted(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	print_stacks(t_stacks stacks);

#endif

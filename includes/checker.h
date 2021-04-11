/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/11 19:18:58 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include "../libft/libft.h"
# include "stack.h"

typedef struct s_stacks
{
	t_stack		a;
	t_stack		b;
}				t_stacks;

bool	validate_params(int argc, char **argv);
void	validate_args(int argc, char **argv);
void	build_stacks(int argc, char **argv, t_stacks *stacks);
void	read_and_execute_commands(t_stacks *stacks);
void	operations(char *op, t_stacks *stacks);
void	check_if_is_sort(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	print_stacks(t_stacks stacks);

#endif

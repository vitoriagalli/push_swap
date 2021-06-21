/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/22 01:31:26 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libstack.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647


typedef struct s_info
{
	char		op[4];
	bool		top;
	int			n_op;
	int			ind;
	int			size;
}				t_info;


typedef struct s_actions
{
	t_info		a;
	t_info		b;
	int			total;
}				t_actions;


/*
** sorting algorithms utils
*/

void	index_elements_in_stack_a(t_stack *a);
void	find_markup_head(t_stack *a);
void	markup_head(t_stack *a);

void	find_smallest_action_to_push_to_a(t_stacks *stacks, t_actions *def);
void		push_to_stack_a(t_stacks *stacks);

/*
** utils functions
*/

void	call_operation(char *op, t_stacks *stacks);

void	exit_push_swap(t_stacks *stacks);



#endif

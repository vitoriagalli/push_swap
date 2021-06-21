/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 03:06:40 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libstack.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

/*
** sorting algorithms utils
*/

void	index_elements_in_stack_a(t_stack *a);
void	find_markup_head(t_stack *a);
void	markup_head(t_stack *a);

/*
** utils functions
*/

void	call_operation(char *op, t_stacks *stacks);

void	exit_push_swap(t_stacks *stacks);



#endif

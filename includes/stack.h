/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:27 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 15:17:08 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	t_list		*head;
	size_t		size;
}				t_stack;

void	swap(t_stack *stack);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif

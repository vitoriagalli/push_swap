/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:27 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 02:37:42 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	size_t		size;
	int			*arr;
}				t_stack;

void	swap(t_stack *stack);


#endif

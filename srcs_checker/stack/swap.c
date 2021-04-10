/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:49:13 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 02:37:48 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	if (stack->size < 2 || !stack->arr)
		return ;
	stack->arr[0] = stack->arr[0] ^ stack->arr[1];
	stack->arr[1] = stack->arr[0] ^ stack->arr[1];
	stack->arr[0] = stack->arr[0] ^ stack->arr[1];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/15 02:43:41 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libstack.h"

// typedef struct s_push_swap
// {
// 	t_stacks	stacks;
// 	t_list		*operations;
// }				t_push_swap;


typedef struct s_three
{
	int			min;
	int			mid;
	int			max;
}				t_tree;

void	insertion_sort(t_stacks *stacks);
void	sort_list_of_tree(t_stacks *stacks);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/18 16:51:05 by vscabell         ###   ########.fr       */
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

# define POS_0 0
# define POS_1 1
# define POS_2 2

typedef struct s_three
{
	int			min;
	int			mid;
	int			max;
}				t_three;

void	insertion_sort(t_stacks *stacks);
void	sort_list_of_tree(t_stacks *stacks);


int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);


typedef struct s_chunck
{
	int			min;
	int			max;
	int			hold;
	int			lst_init_size;
	int			count;
}				t_chunck;



#endif

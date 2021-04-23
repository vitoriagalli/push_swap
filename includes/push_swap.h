/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 21:36:16 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libstack.h"

# define POS_0 0
# define POS_1 1
# define POS_2 2
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_range
{
	int			min;
	int			mid;
	int			max;
}				t_range;

typedef struct s_node
{
	int				value;
	size_t			posit;
	bool			top_half;
	struct s_node	*next;
}					t_node;

/*
** sorting algoritms
*/

void	sort_list_of_two(t_stacks *stacks);
void	sort_list_of_three(t_stacks *stacks);
void	sort_list_of_five(t_stacks *stacks);
void	sort_list_of_many(t_stacks *stacks);
void	push_to_a(t_stacks *stacks);

/*
** sorting algoritms utils
*/

void	rotate_and_push_two_values(t_stacks *stacks, char *op, t_node *max);
void	rotate_and_push_three_values(t_stacks *stacks, char *op, t_node *max);
// void	rotate_and_push_four_values(t_stacks *stacks, char *op, t_node *max);
int		get_median(t_list *lst);
int		get_dynamic_median(t_list *lst, size_t init_size);
void	rotate_and_push_value(t_stacks *stacks, char *op, int value);


/*
** utils nodes
*/

t_node	*ft_nodenew(t_stack *stack, int val_max);
void	ft_nodeadd_back(t_node **lst, t_node *new);
void	sort_nodes_by_posit(t_node **begin_list, bool(*cmp)(int, int));
void	ft_nodeclear(t_node **lst);

/*
** utils functions
*/

void	call_operation(char *op, t_stacks *stacks);
int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);
void	ft_sort_int_tab(int *tab, int size);
void	exit_push_swap(t_stacks *stacks, t_node **max);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:33 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/23 16:43:38 by vscabell         ###   ########.fr       */
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


// nao usado
typedef struct s_nodes
{
	t_node		*max;
	int			posit[5];
}				t_nodes;



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

void	rotate_and_push_three_values(t_stacks *stacks, char *cmd, t_nodes *n);
int		get_median(t_list *lst);
int		get_dynamic_median(t_list *lst, size_t init_size);

/*
** utils functions
*/

void	call_operation(char *op, t_stacks *stacks);
void	rotate_and_push_value(t_stacks *stacks, char *cmd, int value);
int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);
int		get_max_value_but_n(t_stack *stack, int n);


t_node	*ft_nodenew(t_stack *stack, int val_max);
// void	sort_nodes_by_posit(t_node **begin_list);
void	sort_nodes_by_posit(t_node **begin_list, bool(*cmp)(size_t, size_t));
bool	ascending(int a, int b);
bool	descending(int a, int b);


#endif

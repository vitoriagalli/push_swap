/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:27 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 04:00:37 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_H
# define LIBSTACK_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int			numb;
	int			index;
	bool		keep_a;
	void		*next;
	void		*previous;
}				t_node;

typedef struct s_stack
{
	t_node		*head;
	size_t		size;
	int			markup_head;
}				t_stack;

typedef struct s_stacks
{
	t_stack		a;
	t_stack		b;
	int			n_op;
}				t_stacks;

void	swap(t_stack *stack);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
char	**unify_args(int argc, char **argv);
void	validate_args(int argc, char **argv);
bool	validate_params(char **argv);
void	build_stacks(char **argv, t_stacks *stacks);
void	operations(char *op, t_stacks *stacks);
bool	is_sorted(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	print_stacks(t_stacks stacks);
t_node	*ft_nodenew(int numb);
void	ft_nodeadd_back(t_node **lst, t_node *new);
void	ft_nodeadd_front(t_node **lst, t_node *new);

#endif

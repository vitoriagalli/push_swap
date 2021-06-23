/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:19:07 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/23 00:25:25 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** put all the stack elements in an array in ascending order
*/
static int	*create_table_with_sorting_values(t_stack *a)
{
	t_node	*tmp;
	int		*tab;
	size_t	i;

	tab = ft_calloc(1, a->size * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	tmp = a->head;
	while (tmp && i < a->size)
	{
		tab[i] = tmp->numb;
		tmp = tmp->next;
		i++;
	}
	sort_int_tab(tab, a->size);
	return (tab);
}

/*
** for each node in the stack, indicate the according index
*/
static void	atribute_indexes_in_stack_struct(t_stack *a, int *tab)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	while (tmp)
	{
		i = 0;
		while (tmp->numb != tab[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
}

/*
** make an index mark according to the values in ascending order
*/
void	index_elements_in_stack_a(t_stacks *stacks)
{
	int		*tab;

	tab = create_table_with_sorting_values(&stacks->a);
	if (!tab)
		exit_push_swap(stacks);
	atribute_indexes_in_stack_struct(&stacks->a, tab);
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:19:07 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/21 03:38:13 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	*create_table_with_sorting_values(t_stack *a)
{
	t_node	*tmp;
	int		*tab;
	size_t	i;

	tab = malloc(a->size * sizeof(int));
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
	ft_sort_int_tab(tab, a->size);
	return (tab);
}

void	atribute_indexes_in_stack_struct(t_stack *a, int *tab)
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
		// ft_printf("%i\n", i);
	}

}

void	index_elements_in_stack_a(t_stack *a)
{
	int		*tab;

	tab = create_table_with_sorting_values(a);
	atribute_indexes_in_stack_struct(a, tab);
	free(tab);
}

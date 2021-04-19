/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:41:18 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/20 00:26:02 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	quicksort(int number[25],int first,int last)
// {
// 	int	i;
// 	int	j;
// 	int	pivot;
// 	int	temp;

// 	if(first < last)
// 	{
// 		pivot = first;
// 		i = first;
// 		j = last;

// 		while(i<j)
// 		{
// 			while(number[i] <= number[pivot] && i < last)
// 				i++;
// 			while(number[j] > number[pivot])
// 				j--;
// 			if(i < j)
// 			{
// 				temp = number[i];
// 				number[i] = number[j];
// 				number[j] = temp;
// 			}
// 		}

// 		temp = number[pivot];
// 		number[pivot] = number[j];
// 		number[j] = temp;
// 		quicksort(number, first, j-1);
// 		quicksort(number, j+1, last);
// 	}
// }

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


int	get_median(t_list *lst)
{
	int		*tab;
	int		median;
	size_t	size;
	size_t	i;

	if (!lst)
		return (-2147483648);
	size = ft_lstsize(lst);
	tab = malloc(size * sizeof(int));
	if (!tab)
		exit(-1);		//check exit funct
	i = 0;
	while (lst && i < size)
	{
		tab[i] = lst->numb;
		lst = lst->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < (size / 2))
		i++;
	median = tab[i];
	free(tab);
	return (median);
}

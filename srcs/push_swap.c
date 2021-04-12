/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:50 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/13 01:50:17 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	clear_push_swap(t_push_swap *push_swap)
{
	clear_stacks(&push_swap->stacks);
	ft_lstclear(&push_swap->operations, ft_free);
}

void	ft_lst_print(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}

void	calculate_opperations(t_push_swap *push_swap, char *op)
{
	op = "sa";
	operations(op, &push_swap->stacks);
}

void	game_on(t_push_swap *push_swap)
{
	bool	sort;
	char	op;

	sort = is_sorted(&push_swap->stacks);
	while (sort == false)
	{
		calculate_opperations(push_swap, &op);
		ft_lstadd_back(&push_swap->operations, ft_lstnew(ft_strdup("sa")));
		sort = is_sorted(&push_swap->stacks);
	}
	ft_lst_print(push_swap->operations);
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	validate_args(argc, argv);
	build_stacks(argc, argv, &push_swap.stacks);
	game_on(&push_swap);
	clear_push_swap(&push_swap);
	return (EXIT_SUCCESS);
}

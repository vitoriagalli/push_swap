/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:59:46 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 20:56:08 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	sorted_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static bool	empty_stack(t_stack *stack)
{
	if (stack->size == 0 && !stack->head)
		return (true);
	return (false);
}

void	check_if_is_sort(t_stacks *stacks)
{
	if (sorted_stack(&stacks->a) && empty_stack(&stacks->b))
	{
		ft_printf("OK\n");
		clear_stacks(*stacks);
		exit(EXIT_SUCCESS);
	}
}

void	read_and_execute_commands(t_stacks *stacks)
{
	char	*cmd;
	int		ret;

	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &cmd);
		if (ret < 0)
			return ;
		if (ret == 0)
			break ;
		operations(cmd, stacks);
		free(cmd);
		print_stacks(*stacks);
	}
	check_if_is_sort(stacks);
}

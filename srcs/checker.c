/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/13 01:36:35 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_and_execute_commands(t_stacks *stacks)
{
	char	*cmd;
	int		ret;

	print_stacks(*stacks);
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &cmd);
		if (ret <= 0)
			break ;
		operations(cmd, stacks);
		free(cmd);
		print_stacks(*stacks);
	}
	free(cmd);
}

void	check_if_is_sorted(t_stacks *stacks)
{
	bool	sorted;

	sorted = is_sorted(stacks);
	if (sorted)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate_args(argc, argv);
	build_stacks(argc, argv, &stacks);
	read_and_execute_commands(&stacks);
	check_if_is_sorted(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

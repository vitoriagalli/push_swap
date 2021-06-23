/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/06/24 00:25:04 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

static void	read_and_execute_commands(t_stacks *stacks, bool verbose)
{
	char	*cmd;
	int		ret;

	if (verbose)
		print_stacks(*stacks);
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &cmd);
		if (ret <= 0)
			break ;
		operations(cmd, stacks);
		free(cmd);
		if (verbose)
			print_stacks(*stacks);
	}
	free(cmd);
}

static void	check_if_is_sorted(t_stacks *stacks)
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
	char		**argv_split;
	bool		verbose;

	if (argc == 1)
		return (EXIT_FAILURE);
	verbose = !(ft_strcmp(argv[1], "-v"));
	if (verbose)
		argv_split = unify_args(--argc, &argv[1]);
	else
		argv_split = unify_args(argc, argv);
	validate_args(argc, argv_split);
	build_stacks(argv_split, &stacks);
	ft_array_clear((void **)argv_split);
	read_and_execute_commands(&stacks, verbose);
	check_if_is_sorted(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}

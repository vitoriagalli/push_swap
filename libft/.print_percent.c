/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:06:43 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/12 03:03:25 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent(t_flags *flags)
{
	int	space;
	int	zero;

	zero = flags->width > 1 && flags->zero ? flags->width - 1 : 0;
	space = flags->width > 1 && !zero ? flags->width - 1 : 0;
	flags->ret += 1 + zero + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

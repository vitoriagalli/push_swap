/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:07:31 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/18 01:56:00 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(va_list ap, t_flags *flags)
{
	char	c;
	int		space;

	c = va_arg(ap, int);
	space = flags->width > 1 ? flags->width - 1 : 0;
	flags->ret += 1 + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

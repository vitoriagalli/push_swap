/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .print_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:11:42 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/04 02:53:55 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_string(t_flags *flags, char *str, int len)
{
	int		space;
	int		zero;

	zero = 0;
	space = 0;
	if (flags->width > len && flags->zero)
		zero = flags->width - len;
	if (flags->width > len && !zero)
		space = flags->width - len;
	flags->ret += len + space + zero;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	while (len--)
		ft_putchar_fd(*str++, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void	print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flags->precision > 0 && flags->precision < (int)ft_strlen(str))
		len = flags->precision;
	else if (!(flags->dot && !flags->precision))
		len = ft_strlen(str);
	handle_string(flags, str, len);
}

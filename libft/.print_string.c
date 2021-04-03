/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:11:42 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/12 03:02:34 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;
	int		space;
	int		zero;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (flags->precision > 0 && flags->precision < (int)ft_strlen(str))
		len = flags->precision;
	else
		len = (flags->dot && !flags->precision) ? 0 : ft_strlen(str);
	zero = flags->width > len && flags->zero ? flags->width - len : 0;
	space = flags->width > len && !zero ? flags->width - len : 0;
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

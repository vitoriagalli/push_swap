/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:34:19 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/04 01:29:59 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	lenplus;

	lenplus = ft_strlen(s1) + 1;
	s2 = malloc(lenplus * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, lenplus);
	return (s2);
}

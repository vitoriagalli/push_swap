/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:50:16 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/03 23:04:25 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!(new_ptr = calloc(sizeof(char), size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

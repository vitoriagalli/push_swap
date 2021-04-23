/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:46:51 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/04 01:21:49 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ft_lst;
	t_list	*elem_f;

	if (!lst)
		return (NULL);
	ft_lst = ft_lstnew((*f)(lst->content));
	if (!ft_lst)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		elem_f = ft_lstnew((*f)(tmp->content));
		if (!elem_f)
		{
			ft_lstclear(&ft_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ft_lst, elem_f);
		tmp = tmp->next;
	}
	return (ft_lst);
}
